`timescale 1ns / 1ps

module topcpu(
    input CLK100MHZ,
    input [8:0] SW,
    output CG, CF, CE, CD, CC, CB, CA,
    output [7:0] AN,
    output DP,
	output [15:0] LED
);
// mips 上板子的顶层文件
	wire [31:0] out, addr, PC;
	wire mw, clk1, clk2, clk3, clk4, clk5, clk1hz;
	wire [4:0] ReadReg;
	wire [5:0] ReadMem;
	wire [31:0] RegData, MemData;
	wire cpuclk;
	wire [31:0] AluOut, PCNext;

	assign CLK = CLK100MHZ & (~SW[8]);
	assign LED[15:0] = {clk1hz, PCNext[10:4], PC[11:4]};
	
	top topmips(clk1hz, SW[7], out, addr, mw, ReadReg, ReadMem, RegData, MemData, PC, AluOut, PCNext);
	display displaydata(SW[0], SW[6:1], RegData, MemData, clk2, SW[7], ReadReg, ReadMem, {CG, CF, CE, CD, CC, CB, CA}, AN[7:0], DP, AluOut);
	clkdiv clocker1(CLK100MHZ, SW[7], clk1, clk2, clk3);
	clkdiv clocker2(CLK, SW[7], clk4, clk5, clk1hz);

endmodule
