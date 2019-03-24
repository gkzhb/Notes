`timescale 1ns / 1ps

module controller(
	input [5:0] Op, Funct,
	input Zero,
	output MemToReg, MemWrite,
	output PCSrc, AluSrc,
	output RegDst, RegWrite,
	output Jump,
	output [2:0] AluCtl,
	output ExtOp);

	wire [2:0] AluOp;
	wire Branch;

	maindec md(Op, MemToReg, MemWrite, Branch, AluSrc, RegDst, RegWrite, Jummp, AluOp, Bne, ExtOp);
	aludec ad(Funct, AluOp, AluCtl);

	assign PCSrc = Branch & (Bne ^ Zero);
endmodule
