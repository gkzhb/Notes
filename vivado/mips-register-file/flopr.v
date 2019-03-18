`timescale 1ns / 1ps

module flopr #(parameter WIDTH = 8)
	(input CLK, RESET,
	input [WIDTH - 1:0] d,
	output reg [WIDTH - 1:0] q);

	always @(posedge CLK, posedge RESET)
		if (RESET)
			q <= 0;
		else
			q <= d;
endmodule
