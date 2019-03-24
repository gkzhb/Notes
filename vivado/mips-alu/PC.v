`timescale 1ns / 1ps

module PC #(parameter WIDTH = 32)
	(input CLK, RESET,
	input [WIDTH - 1:0] newPC,
	output reg [WIDTH - 1:0] curPC);

	always @(posedge CLK, posedge RESET)
		if (RESET)
			curPC <= 0;
		else
			curPC <= newPC;
endmodule
