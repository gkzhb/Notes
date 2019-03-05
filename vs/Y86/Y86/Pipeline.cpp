#include "Pipeline.h"
#include <vector>
#include<iostream>
#include <iomanip>

#define TEST_STATE

using namespace std;
static Fetch fCur, fIn;	// fCur: current fetch, fIn: input fetch
static Decode dCur, dIn;
static Execute eCur, eIn;
static Memory mCur, mIn;
static Write wCur, wIn;
static Condition cc;
static StoreChange sC;
static vector<char>* mem;
static long long reg[15];
static long long mem_addr, mem_data;
static bool mem_write;
static bool imem_error;
static bool instr_valid;
static bool dmem_error;
static bool set_cc;
static int CLK = 0;

static const char* REGNAME[16] = {
	"%rax", "%rcx", "%rdx", "%rbx", "%rsp",
	"%rbp", "%rsi", "%rdi", "%r8", "%r9",
	"%r10", "%r11", "%r12", "%r13", "%r14", "NONE" };
static const char* STATNAME[5] = {
	"NULL", "AOK", "HLT", "ADR", "INS" };
static const char* INSTR[] = {
	"halt", "nop", "rrmovq", "irmovq",
	"rmmovq", "mrmovq", "OPq", "j",
	"call", "ret", "pushq", "popq", "cmov" };
static const char* JXX[] = { "mp", "le", "l", "e", "ne", "ge", "g" };

#define RRSP 4
#define RNONE 15
#define IRET 9
#define INOP 1

long long deal(long long PC)//处理小端法
{
	long long res = 0;
	for (int i = 0; i < 8; i++)
	{
		res |= (long long)((unsigned char)((*mem)[PC + i])) << (8 * i);
	}
#ifdef TEST_DEAL
	cout << hex << PC << " : "
		<< res << endl << endl;
#endif
	return res;
}

// 写入 8 字节数据到内存中
// addr: 内存地址
// val: 需要写入的 8 字节数据
void writeMem(long long addr, long long val)
{
	for (int i = 0; i < 8; i++)
	{
		(*mem)[addr] = val & 0xff;
		val >>= 8;
		addr++;
	}
}

bool judgeCode(char code)//判断第一个字符
{
	char icode = (code >> 4) & 0xf;
	char ifun = code & 0xf;
	if (icode >= 0 && icode <= 0xb)
	{
		if (icode != 6 && icode != 7 && icode != 2)//!Opq && !JXX && !rrmovq && !cmovq
		{
			if (ifun != 0)
				return false;
		}
		else
		{
			if (icode == 2 || icode == 7)
			{
				if (ifun > 6 || ifun < 0)
					return false;
			}
			else
			{
				if (ifun < 0 || ifun > 3)
					return false;
			}
		}
		return true;
	}
	else
		return false;
}

void ALU(long long ALUA, long long ALUB, char fun)//加法器
{
	long long res;
	switch (fun) {
	case 0:
		res = ALUA + ALUB;
		break;
	case 1:
		res = ALUB - ALUA;
		break;
	case 2:
		res = ALUB & ALUA;
		break;
	case 3:
		res = ALUB ^ ALUA;
	}
	mIn.valE = res;
	if (set_cc && wCur.stat == Condition::AOK && wIn.stat == Condition::AOK)//如果后续阶段出错则不能再修改stat
	{
		cc.ZF = res == 0;
		cc.SF = res < 0;
		cc.OF = (ALUA > 0 && ALUB > 0 && res < 0) || (ALUA < 0 && ALUB < 0 && res >= 0);
	}
}
bool cond(char ifun)
{
	switch (ifun)
	{
	case 1:// le
		return (cc.SF ^ cc.OF) | cc.ZF;
	case 2:// l
		return cc.SF ^ cc.OF;
	case 3:// e
		return cc.ZF;
	case 4:// ne
		return !cc.ZF;
	case 5:// ge
		return !(cc.SF ^ cc.OF);
	case 6:// g
		return !(cc.SF ^ cc.OF) & !cc.ZF;
	default:
		return 1;
	}
	//return 1;
}

void selectPC()
{
	if (mCur.icode == 7 && !mCur.Cnd)//预测失误，没有跳转
		cc.PC = mCur.valA;
	else if (wCur.icode == 9)//ret到达W时
		cc.PC = wCur.valM;
	else
		cc.PC = fCur.predPC;
}

void Sel_FwdA()//更新Execute阶段的valA
{
	if (dCur.icode == 8 || dCur.icode == 7)//此处优先级不能调换
		eIn.valA = dCur.valP;
	else if (eIn.srcA == mIn.dstE)
		eIn.valA = mIn.valE;
	else if (eIn.srcA == mCur.dstM)
		eIn.valA = wIn.valM;
	else if (eIn.srcA == mCur.dstE)
		eIn.valA = mCur.valE;//wIn.valE
	else if (eIn.srcA == wCur.dstM)
		eIn.valA = wCur.valM;
	else if (eIn.srcA == wCur.dstE)
		eIn.valA = wCur.valE;
	else
	{
		switch (dCur.icode)
		{
		case 2:
		case 4:
		case 6:
		case 0xa:
			eIn.valA = reg[dCur.rA];
			break;
		case 9:
		case 0xb:
			eIn.valA = reg[RRSP];
		}
	}
}

void FwdB()//更新Execute阶段的valB
{
	if (eIn.srcB == eCur.dstE)
		eIn.valB = mIn.valE;
	else if (eIn.srcB == mCur.dstM)
		eIn.valB = wIn.valM;
	else if (eIn.srcB == mCur.dstE)
		eIn.valB = mCur.valE;//wIn.valE
	else if (eIn.srcB == wCur.dstM)
		eIn.valB = wCur.valM;
	else if (eIn.srcB == wCur.dstE)
		eIn.valB = wCur.valE;
	else
	{
		switch (dCur.icode)
		{
		case 4:
		case 6:
		case 5:
			eIn.valB = reg[dCur.rB];
			break;
		case 7:
		case 8:
		case 9:
		case 0xa:
		case 0xb:
			eIn.valB = reg[RRSP];
		}
	}
}

void control()
{
	fIn.stall = ((eCur.icode == 5 || eCur.icode == 0xb) && (eCur.dstM == dCur.rA || eCur.dstM == dCur.rB))
		|| (dCur.icode == IRET || eCur.icode == IRET || mCur.icode == IRET);

	dIn.stall = (eCur.icode == 5 || eCur.icode == 0xb) && (eCur.dstM == eIn.srcA || eCur.dstM == eIn.srcB);

	dIn.bubble = (eCur.icode == 7 && !mIn.Cnd) || (!((eCur.icode == 5 || eCur.icode == 0xb) && (eCur.dstM == dCur.rA || eCur.dstM == dCur.rB)) &&
		(dCur.icode == IRET || eCur.icode == IRET || mCur.icode == IRET));

	eIn.bubble = (eCur.icode == 7 && !mIn.Cnd) ||
		((eCur.icode == 5 || eCur.icode == 0xb) && (eCur.dstM == eIn.srcA || eCur.dstM == eIn.srcB));



	mIn.bubble = mCur.stat != Condition::AOK || wCur.stat != Condition::AOK;

	wIn.stall = wCur.stat != Condition::AOK;
}

void refresh()
{

	if (fIn.stall)//refresh F
		fCur = fCur;
	else
		fCur = fIn;

	if (dIn.stall)// refresh D
		dCur = dCur;
	else if (dIn.bubble)
	{
		dCur.icode = INOP;
		dCur.stat = Condition::AOK;
	}
	else
		dCur = dIn;

	if (eIn.bubble)//refresh E
	{
		eCur.icode = INOP;
		eCur.stat = Condition::AOK;
		eCur.dstE = 0xf;
		eCur.dstM = 0xf;
	}
	else
		eCur = eIn;

	if (mIn.bubble)//refresh M
	{
		mCur.icode = INOP;
		mCur.stat = Condition::AOK;
	}
	else
		mCur = mIn;

	if (wIn.stall)//refresh W
		wCur = wCur;
	else
		wCur = wIn;

	fIn.clear();
	eIn.clear();
	dIn.clear();
	mIn.clear();
	wIn.clear();
}

void StoreChange::print()
{
	// TODO 修改输出格式
	static char lastReg1 = 0xf, lastReg2 = 0xf;
	cout << dec << CLK << endl;
	cout << "0x" << hex << setw(3) << cc.PC << " "
		<< STATNAME[cc.Stat] << " " << int(cc.ZF)
		<< int(cc.SF) << int(cc.OF) << endl;

	for (int i = 0; i < 15; i++)
	{
		cout << setw(16) << setfill('0') << hex << regOut[i] << endl;
	}
	/*for (int i = 0; i < 15; i++)
	if (regIn[i] != regOut[i])
	{
	cout << REGNAME[i] << ": ";
	if (i == 8 || i == 9)
	cout << ' ';
	cout << setw(16) << setfill('0') << hex << regIn[i]
	<< " " << setw(16) << setfill('0') << hex << regOut[i] << endl;
	}*/

	for (vector<long long>::size_type i = 0; i < memAddr.size(); i++)
		// if (memIn[i] != memOut[i])
		// if (memAddr[i] == mem_addr)

	{
		cout << "0x" << setw(3) << setfill('0') << hex << memAddr[i] << " "
			<< setw(16) << setfill('0') << hex << memIn[i] << " "
			<< setw(16) << setfill('0') << hex << memOut[i] << endl;
	}
#ifdef TEST_REG
	cout << endl;
	for (int i = 0; i < 15; i++)
	{
		cout << REGNAME[i] << ": ";
		if (i == 8 || i == 9)
			cout << ' ';
		cout << "0x" << setw(16) << setfill('0') << hex << regIn[i]
			<< "\t0x" << setw(16) << setfill('0') << hex << regOut[i] << endl;
	}
#endif


	cout << "W " << STATNAME[wCur.stat] << " " << int(wCur.icode) << " "
		<< wCur.valE << " " << wCur.valM << " " << REGNAME[wCur.dstE] << " " << REGNAME[wCur.dstM] << endl;
	cout << "M " << STATNAME[mCur.stat] << " " << int(mCur.icode) << " "
		<< int(mCur.Cnd) << " " << mCur.valE << " " << mCur.valA << " "
		<< REGNAME[mCur.dstE] << " " << REGNAME[mCur.dstM] << endl;
	cout << "E " << STATNAME[eCur.stat] << " " << int(eCur.icode) << " "
		<< int(eCur.ifun) << " " << eCur.valC << " " << eCur.valA << " "
		<< eCur.valB << " " << REGNAME[eCur.dstE] << " " << REGNAME[eCur.dstM] << " "
		<< REGNAME[eCur.srcA] << " " << REGNAME[eCur.srcB] << endl;
	cout << "D " << STATNAME[dCur.stat] << " " << int(dCur.icode) << " " << int(dCur.ifun) << " " << REGNAME[dCur.rA]
		<< " " << REGNAME[dCur.rB] << " " << dCur.valC << " " << dCur.valP << endl;
	cout << "F " << hex << fCur.predPC << endl;
	cout << "#" << endl;
}

void Fetch::run()
{
	selectPC();
	imem_error = cc.PC >= (*mem).size();//判断指令地址是否合法
	instr_valid = judgeCode((*mem)[cc.PC]);//判断指令是否合法
	char c = (*mem)[cc.PC];
	dIn.icode = (c >> 4) & 0xf;
	dIn.ifun = c & 0xf;
	switch (dIn.icode)
	{
	case 0://halt
		break;
	case 1://nop
		dIn.valP = cc.PC + 1;// TODO
		break;
	case 2://rrmovq
	case 6://OPq
	case 0xa://pushq
	case 0xb://popq
		c = (*mem)[cc.PC + 1];
		dIn.rA = (c >> 4) & 0xf;
		dIn.rB = c & 0xf;
		dIn.valP = cc.PC + 2;
		break;
	case 3://irmovq
	case 4://rmmovq
	case 5://mrmovq
		c = (*mem)[cc.PC + 1];
		dIn.rA = (c >> 4) & 0xf;
		dIn.rB = c & 0xf;
		dIn.valC = deal(cc.PC + 2);
		dIn.valP = cc.PC + 10;
		break;
	case 7://JXX
	case 8://call
		dIn.valC = deal(cc.PC + 1);
		dIn.valP = cc.PC + 9;
		break;
	case 9://ret
		dIn.valP = cc.PC + 1;
		break;
	default:
		cc.Stat = Condition::INS;
	}
	fIn.predPC = (dIn.icode == 7 || dIn.icode == 8) ? dIn.valC : dIn.valP;
	if (imem_error == 1)
		dIn.stat = Condition::ADR;
	else if (!instr_valid)
		dIn.stat = Condition::INS;
	else if (dIn.icode == 0)
		dIn.stat = Condition::HLT;
	else
		dIn.stat = Condition::AOK;
}

void Decode::run()
{
	eIn.icode = dCur.icode;
	eIn.ifun = dCur.ifun;
	eIn.valC = dCur.valC;//valC
	switch (dCur.icode)//更新Exucute阶段的srcA数据
	{
	case 2://rrmovq
	case 4://rmmovq
	case 6://mrmovq
	case 0xa://pushq
		eIn.srcA = dCur.rA;
		break;
	case 9://ret
	case 0xb://popq
		eIn.srcA = RRSP;//%rsp
		break;
	default:
		eIn.srcA = RNONE;//none
	}
	switch (dCur.icode)//更新Exucute阶段的srcB数据
	{
	case 4://rmmovq
	case 5://mrmovq
	case 6://Opq
		eIn.srcB = dCur.rB;
		break;
	case 8://call
	case 9://ret
	case 0xa://pushq
	case 0xb://popq
		eIn.srcB = RRSP;//%rsp
		break;
	default:
		eIn.srcB = RNONE;//none
	}
	Sel_FwdA();
	FwdB();
	switch (dCur.icode)//更新Exucute阶段的dstE数据
	{
	case 2://rrmovq
	case 3://irmovq
	case 6://Opq
		eIn.dstE = dCur.rB;
		break;
	case 8://call
	case 9://ret
	case 0xa://pushq
	case 0xb://popq
		eIn.dstE = RRSP;//%rsp;
		break;
	default:
		eIn.dstE = RNONE;//none
	}
	switch (dCur.icode)//更新Exucute阶段的dstM数据
	{
	case 5:
	case 0xb:
		eIn.dstM = dCur.rA;
		break;
	default:
		eIn.dstM = RNONE;//none
	}
	eIn.stat = dCur.stat;
}

void Execute::run()
{
	long long ALUA = 0, ALUB = 0;
	mIn.icode = eCur.icode;
	char fun = (eCur.icode == 6) ? eCur.ifun : 0;
	switch (eCur.icode)// ALUA
	{
	case 2://rrmovq
	case 6://OPq
		ALUA = eCur.valA;
		break;
	case 3://irmovq
	case 4://rmmovq
	case 5://mrmovq
		ALUA = eCur.valC;
		break;
	case 8://call
	case 0xa://pushq
		ALUA = -8;
		break;
	case 9://ret
	case 0xb://popq
		ALUA = 8;
	}
	switch (eCur.icode)// ALUB
	{
	case 4://rmmovq
	case 5://mrmovq
	case 6://Opq
	case 8://call
	case 9://ret
	case 0xa://pushq
	case 0xb://popq
		ALUB = eCur.valB;
		break;
	case 2://rrmovq
	case 3://irmovq
		ALUB = 0;
	}
	set_cc = (eCur.icode == 6) && mCur.stat == Condition::AOK && wCur.stat == Condition::AOK; // Changed from control
	ALU(ALUA, ALUB, fun);
	if (eCur.icode == 7 || eCur.icode == 2)
		mIn.Cnd = cond(eCur.ifun);
	else
		mIn.Cnd = 1;
	mIn.valA = eCur.valA;	// mIn.valA
	mIn.dstE = mIn.Cnd ? eCur.dstE : RNONE;	// mIn.dstE
	mIn.dstM = eCur.dstM;	// mIn.dstM
	mIn.stat = eCur.stat;
}

void Memory::run()
{
	wIn.icode = mCur.icode;
	wIn.valE = mCur.valE;
	wIn.dstE = mCur.dstE;
	wIn.dstM = mCur.dstM;

	switch (mCur.icode)//更新mem_addr
	{
	case 4://rmmovq
	case 5://mrmovq
	case 8://call
	case 0xa://pushq
		mem_addr = mCur.valE;
		break;
	case 9://ret
	case 0xb://popq
		mem_addr = mCur.valA;
		break;
	default:
		mem_addr = 0xffffffff;
	}
	if (mem_addr != 0xffffffff)
		dmem_error = (mem_addr >= (*mem).size());
	else
		dmem_error = 0;
	bool mem_read = (mCur.icode == 5 || mCur.icode == 9 || mCur.icode == 0xb);
	mem_write = (mCur.icode == 4 || mCur.icode == 0xa || mCur.icode == 8) && !dmem_error;
	if (mem_read)
		wIn.valM = deal(mem_addr);		//流水线在此前合并了valA,valP TODO 循环读取 8 字节
	if (mem_write)
	{
		vector<long long>::size_type i = 0;
		for (; i < sC.memAddr.size(); i++)
			if (mem_addr == sC.memAddr[i])
			{
				sC.memOut[i] = mCur.valA;
				break;
			}
		if (i == sC.memAddr.size())
		{
			sC.memAddr.push_back(mem_addr);
			sC.memIn.push_back(deal(mem_addr));
			sC.memOut.push_back(mCur.valA);
		}
		writeMem(mem_addr, mCur.valA);
	}
	if (dmem_error)
		wIn.stat = Condition::ADR;
	else
		wIn.stat = mCur.stat;
}

void Write::run()
{
	if (wCur.stat == Condition::AOK)
	{
		if (wCur.dstE != 0xf)
			sC.regOut[wCur.dstE] = reg[wCur.dstE] = wCur.valE;
		if (wCur.dstM != 0xf)
			sC.regOut[wCur.dstM] = reg[wCur.dstM] = wCur.valM;
	}

	cc.Stat = (wCur.stat == 1) ? Condition::AOK : wCur.stat;
}

void execute(vector<char> &memory)
{
	mem = &memory;
	for (int i = 0; i < 15; i++)
	{
		sC.regOut[i] = sC.regIn[i] = 0;
	}
	while (Condition::AOK == cc.Stat)
	{
		mCur.run();
		eCur.run();
		dCur.run();
		fCur.run();
		// 更新寄存器的数据
		wCur.run();	// Update reg
		control();
		refresh();
#ifdef TEST_STATE
		sC.print();
#endif
		CLK++;
	}
	cout << "##" << endl;
	// sC.print();
}
