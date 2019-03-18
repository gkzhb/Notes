`timescale 1ns / 1ps

module signext(
	input [15:0] A,
	output [31:0] Y);

	assign Y = {{16{A[15]}}, A};
endmodule
