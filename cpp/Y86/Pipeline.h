#pragma once
#include<vector>
#include<string>

void execute(std::vector<char> &mem);
long long deal(long long PC);
bool judgeCode(char code);
void ALU(long long ALUA, long long ALUB, char fun);
bool cond(char ifun);
void selectPC();
void Sel_FwdA();
void FwdB();
void control();
void refresh();

class Fetch
{
public:
	Fetch(): predPC(-1), stall(0) { }
	void run();
	void clear() { predPC = -1; }
	char stall;
	long long predPC;
};

class Decode
{
public:
	Decode(): icode(1), ifun(0), rA(0xf), rB(0xf), valC(0), valP(0), stat(1), stall(0), bubble(0) { }
	void run();
	void clear() { icode =1 , ifun = 0, rA = 0xf, rB = 0xf, valC = 0, valP = 0, stat = 1, stall = 0, bubble = 0; }
	char icode, ifun, rA, rB, stat, stall, bubble;
	long long valC, valP;
};

class Execute
{
public:
	Execute(): icode(1), ifun(0), valC(0), valA(0), valB(0), dstE(0xf), dstM(0xf), srcA(0xf), srcB(0xf), stat(1), bubble(0) { }
	void clear() { icode = 1, ifun = 0, valC = 0, valA = 0, valB = 0, dstE = 0xf, dstM = 0xf, srcA = 0xf, srcB = 0xf, stat = 1, bubble = 0; }
	void run();
	char icode, ifun, stat, bubble;
	long long valC, valA, valB, dstE, dstM, srcA, srcB;
};

class Memory
{
public:
	Memory(): icode(1), Cnd(0), valE(0), valA(0), dstE(0xf), dstM(0xf), stat(1), bubble(0) { }
	void clear() { icode = 1, Cnd = 0, valE = 0, valA = 0, dstE = 0xf, dstM = 0xf, stat = 1, bubble = 0; }
	void run();
	bool Cnd;
	char icode, stat, bubble;
	long long valE, valA, dstE, dstM;
};

class Write
{
public:
	void run();
	Write() : icode(1), valE(0), valM(0), dstE(0xf), dstM(0xf), stat(1), stall(0) { }
	void clear() { icode = 1, valE = 0, valM = 0, dstE = 0xf, dstM = 0xf, stat = 1, stall = 0; }
	char icode, stat, stall;
	long long valE, valM, dstE, dstM;
};

class Condition
{
public:
	Condition(): ZF(0), SF(0), OF(0), PC(0), Stat(1) { }
	bool ZF, SF, OF;
	long long  PC;
	char Stat;
	static const char AOK = 1;		// AOK: 正常操作
	static const char HLT = 2;		// HLT: 执行 halt 指令
	static const char ADR = 3;		// ADR: 非法地址
	static const char INS = 4;		// INS: 非法指令
};

class StoreChange
{
public:
	void print();
	long long regIn[15], regOut[15];
	std::vector<long long> memAddr, memIn, memOut;
};
