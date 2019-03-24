`timescale 1ns / 1ps

module mips(
	input CLK, Reset,
	output [31:0] PC,
	input [31:0] Instr,
	output MemWrite,
	output [31:0] AluOut, WriteData,
	input [31:0] ReadData);

	wire MemToReg, AluSrc, RegDst, RegWrite, Jump, PCSrc, Zero, ExtOp;

	wire [2:0] AluCtl;

	controller  c(Instr[31:26], Instr[5:0], Zero, MemToReg, MemWrite, PCSrc,
		AluSrc, RegDst, RegWrite, Jump, AluCtl, ExtOp);
	datapath dp(CLK, Reset, MemToReg, PCSrc, AluSrc, RegDst, RegWrite, Jump,
		AluCtl, ExtOp, Zero, PC, Instr, AluOut, WriteData, ReadData);
endmodule
