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

	maindec md(Op[5:0], MemToReg, MemWrite, Branch, AluSrc, RegDst, RegWrite, Jump, AluOp0[2:0], Bne, ExtOp, RType);
	aludec ad(Funct[5:0], AluOp1[2:0]);
	mux2 #(3) muxaluop(AluOp0[2:0], AluOp1[2:0], RType, AluCtl[2:0]);

	assign PCSrc = Branch & (Bne ^ Zero);
endmodule
