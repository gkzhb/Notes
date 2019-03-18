`timescale 1ns / 1ps

module maindec(
	input [5:0] Op,
	output MemToReg, MemWrite,
	output Branch, AluSrc,
	output RegDst, RegWrite,
	output Jump,
	output [1:0] AluOp);

	reg [8:0] controls;
	assign {RegWrite, RegDst, AluSrc, Branch, MemWrite, MemToReg, Jump, AluOp} = controls;

	always @(*)
		case(Op)
			6'b000000: controls <= 9'b
			// TODO
			default: controls <= 9'bxxxx xxxx x; //Illegal Op
		endcase
endmodule
