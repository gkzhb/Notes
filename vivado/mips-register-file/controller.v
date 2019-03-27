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

	wire [2:0] AluOp0, AluOp1;
	wire Branch, RType;

	maindec md(Op, MemToReg, MemWrite, Branch, AluSrc, RegDst, RegWrite, Jump, AluOp0, Bne, ExtOp, RType);
	aludec ad(Funct, AluOp1);
	mux2 #(3) muxaluop(AluOp0, AluOp1, RType, AluCtl);

	assign PCSrc = Branch & (Bne ^ Zero);
endmodule
