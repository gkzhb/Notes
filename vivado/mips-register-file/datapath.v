`timescale 1ns / 1ps

module datapath(
	input CLK, Reset, MemToReg, PCSrc,
	input AluSrc, RegDst, RegWrite, Jump,
	input [2:0] AluCtl,
	input ExtOp,
	output Zero,
	output [31:0] PC,
	input [31:0] Instr,
	output [31:0] AluOut, WriteData,
	input [31:0] ReadData,
	input [4:0] ReadReg,
	output [31:0] RegData);

	wire [4:0] WriteReg;
	wire [31:0] PCNext, PCNextBr, PCPlus4, PCBranch;
	wire [31:0] SignImm, SignImmsh;
	wire [31:0] SrcA, SrcB;
	wire [31:0] Result;

	// 下一个 PC 地址
	flopr #(32) PCreg(CLK, Reset, PCNext, PC);
	adder PCadd1(PC, 32'b100, PCPlus4);
	sl2 immsh(SignImm, SignImmsh);
	adder PCadd2(PCPlus4, SignImmsh, PCBranch);
	mux2 #(32) PCbrmux(PCPlus4, PCBranch, PCSrc, PCNextBr);
	mux2 #(32) PCmux(PCNextBr, {PCPlus4[31:28], Instr[25:0], 2'b00}, Jump, PCNext);

	// regfile
	regfile rf(CLK, RegWrite, Instr[25:21], Instr[20:16], WriteReg, Result, SrcA, WriteData, ReadReg, RegData);
	mux2 #(5) wrmux(Instr[20:16], Instr[15:11], RegDst, WriteReg);
	mux2 #(32) resmux(AluOut, ReadData, MemToReg, Result);
	ext se(Instr[15:0], ExtOp, SignImm);

	// ALU
	mux2 #(32) srcbmux(WriteData, SignImm, AluSrc, SrcB);
	ALU alu(SrcA, SrcB, AluCtl, AluOut, Zero);
endmodule
