`timescale 1ns / 1ps

module priorencode4to2(
	input [3:0] A,
	output reg [1:0] S);
// 优先级编码器

	always @(*)
		casez (A)
			4'b???1: S <= 2'b00;
			4'b??10: S <= 2'b01;
			4'b?100: S <= 2'b10;
			4'b1000: S <= 2'b11;
			default: S <= 2'bxx;
		endcase

endmodule
