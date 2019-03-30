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
	output [31:0] RegData,
	output [31:0] PCNext);

	wire [4:0] WriteReg;
	wire [31:0] PCNextBr, PCPlus4, PCBranch;
	wire [31:0] SignImm, SignImmsh;
	wire [31:0] SrcA, SrcB;
	wire [31:0] Result;

	// 下一个 PC 地址
	flopr #(32) PCreg(CLK, Reset, PCNext[31:0], PC[31:0]);
	adder PCadd1(PC[31:0], 32'b100, PCPlus4[31:0]);
	sl2 immsh(SignImm[31:0], SignImmsh[31:0]);
	adder PCadd2(PCPlus4[31:0], SignImmsh[31:0], PCBranch[31:0]);
	mux2 #(32) PCbrmux(PCPlus4[31:0], PCBranch[31:0], PCSrc, PCNextBr[31:0]);
	mux2 #(32) PCmux(PCNextBr[31:0], {PCPlus4[31:28], Instr[25:0], 2'b00}, Jump, PCNext[31:0]);

	// regfile
	regfile rf(CLK, RegWrite, Instr[25:21], Instr[20:16], WriteReg[4:0], Result[31:0], SrcA[31:0], WriteData[31:0], ReadReg[4:0], RegData[31:0]);
	mux2 #(5) wrmux(Instr[20:16], Instr[15:11], RegDst, WriteReg[4:0]);
	mux2 #(32) resmux(AluOut[31:0], ReadData[31:0], MemToReg, Result[31:0]);
	ext se(Instr[15:0], ExtOp, SignImm[31:0]);

	// ALU
	mux2 #(32) srcbmux(WriteData[31:0], SignImm[31:0], AluSrc, SrcB[31:0]);
	ALU alu(SrcA[31:0], SrcB[31:0], AluCtl[2:0], AluOut[31:0], Zero);
endmodule
