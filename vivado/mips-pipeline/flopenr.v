`timescale 1ns / 1ps

module flopenr #(parameter WIDTH = 8)
	(input CLK, RESET, En,
	input [WIDTH - 1:0] d,
	output [WIDTH - 1:0] q);

	reg [WIDTH - 1:0] dt;
	assign q = dt;

	always @(posedge CLK, posedge RESET)
		if (RESET)
			dt <= 0;
		else
			if (En)
				dt <= d;
			else
				dt <= dt;
endmodule
