`timescale 1ns / 1ps

module enreg #(parameter WIDTH = 32)
	(input CLK, EN, Reset
	input [WIDTH - 1:0] Data,
	output [WIDTH - 1:0] Out);

	reg [WIDTH - 1:0] dt;
	assign Out = dt;

	always @(posedge CLK, posedge Reset)
		if (Reset)
			dt <= 0;
		else
			if (EN)
				dt <= Data;
			else
				dt <= dt;
endmodule
