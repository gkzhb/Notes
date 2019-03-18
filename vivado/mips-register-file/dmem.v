`timescale 1ns / 1ps

module dmem(
	input CLK, WE,
	input [31:0] A, WD,
	output [31:0] RD);
// Data Memory 数据存储器

	reg [31:0] RAM[63:0];
	assign RD = RAM[A[31:2]];

	always @(posedge CLK)
		if (WE)
			RAM[A[31:2]] <= WD;
		else
			RAM[A[31:2]] <= RAM[A[31:2]];
endmodule
