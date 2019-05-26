`timescale 1ns / 1ps

module equalcmp(
	input [31:0] A, B,
	output Eq);
	assign Eq = (A == B);
endmodule
