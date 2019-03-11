`timescale 1ns / 1ps

module AddSub(
	input [31:0] A,
	input [31:0] B,
	input Sign,
	output reg [31:0] S
	);

	always @(*)
		case (Sign)
			1'b0: S = A + B;
			1'b1: S = A - B;
		endcase
endmodule
