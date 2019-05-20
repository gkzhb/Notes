`timescale 1ns / 1ps

module mux4 #(parameter WIDTH=8)
	(input [WIDTH - 1:0] A0, A1, A2, A3,
	input [1:0] S,
	output reg [WIDTH - 1:0] Y);

	always @(*)
		case (S)
			2'b00: Y <= A0;
			2'b01: Y <= A1;
			2'b10: Y <= A2;
			2'b11: Y <= A3;
			default: Y <= 0;
		endcase
endmodule
