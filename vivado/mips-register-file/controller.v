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

	wire [2:0] AluOp1, AluOp2;
	wire Branch, RType;

	maindec md(Op, MemToReg, MemWrite, Branch, AluSrc, RegDst, RegWrite, Jump, AluOp1, Bne, ExtOp, RType);
	aludec ad(Funct, AluOp2);
	mux2 #(3) muxaluop(AluOp1, AluOp2, RType, AluCtl);

	assign PCSrc = Branch & (Bne ^ Zero);
endmodule
