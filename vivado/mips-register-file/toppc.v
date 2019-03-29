`timescale 1ns / 1ps

module toppc(
	input [15:0] SW,
	input CLK100MHZ,
	output [15:0] LED);

//	wire [15:0] out1;
//	wire [31:0] out2, out4;
//	regfile regtest(CLK100MHZ, 1'b1, SW[4:0], 5'b0, SW[9:5], {26'b0, SW[15:10]}, {out1, LED}, out2, 5'b0, out4);
	flopr #(15)(CLK100MHZ, SW[15], SW[14:0], LED[14:0]);
	assign LED[15] = 1'b0;
endmodule
