`timescale 1ns / 1ps

module ext(
	input [15:0] A,
	input ExtOp,
	output [31:0] Y);

	assign Y = {{16{A[15] & ExtOp}}, A};
endmodule
