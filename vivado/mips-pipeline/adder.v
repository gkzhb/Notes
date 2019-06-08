`timescale 1ns / 1ps

module adder #(parameter WIDTH = 32)
	(input [WIDTH - 1:0] A, B,
	output [WIDTH - 1:0] Y);

	assign Y = A + B;
endmodule
