`timescale 1ns / 1ps

module topalu(
	input [15:0] SW,
	output [15:0] LED);
	wire [15:0] out;
	wire zero;
	ALU test({26'b0, SW[5:0]}, {26'b0, SW[11:6]}, SW[15:13], {out, LED}, zero);
endmodule
