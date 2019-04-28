`timescale 1ns / 1ps

module top(
	input CLK100MHZ,
	input [15:0] SW,
    output CG, CF, CE, CD, CC, CB, CA,
    output [7:0] AN,
    output DP,
	output [15:0] LED);

	// MIPS + 显示模块 顶层文件
	mips_top mipstop();

endmodule
