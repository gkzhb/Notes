`timescale 1ns / 1ps

module top(
	input CLK100MHZ,
	input [15:0] SW,
    output CG, CF, CE, CD, CC, CB, CA,
    output [7:0] AN,
    output DP,
	output [15:0] LED);

	wire [31:0] DispRegData, DispMemData, PC, PCNext, Instr;
	wire [4:0] DispReadReg;
	wire [5:0] DispReadMem;
	wire clk1, clk2, clk3, clk4, clk5, clk1hz, CLK;

	// SW[15:0] = { Stop 暂停, Reset 重置}
	assign CLK = CLK100MHZ & (~SW[1]);
	assign LED[15] = clk1hz;

	// MIPS + 显示模块 顶层文件
	mips_top mipstop(clk1hz, SW[0], PC, PCNext, DispReadReg, DispReadMem, DispRegData, DispMemData);
	display displaydata(clk2, SW[0], SW[3:2], SW[9:4], DispRegData, DispMemData, DispReadReg, DispReadMem, PC, PCNext, {CG, CF, CE, CD, CC, CB, CA}, AN[7:0], DP);

	clkdiv clocker1(CLK100MHZ, SW[0], clk1, clk2, clk3);
	clkdiv clocker2(CLK, SW[0], clk4, clk5, clk1hz);

endmodule
