`timescale 1ns / 1ps

module top(
	input CLK, Reset,
	output [31:0] WriteData, DataAddr,
	output MemWrite);

	wire [31:0] PC, Instr, ReadData;

	mips mipscpu(CLK, Reset, PC, Instr, MemWrite, DataAddr, WriteData, ReadData);
	imem imemory(PC[7:2], Instr);
	dmem dmemory(CLK, MemWrite, DataAddr, WriteData, ReadData);
endmodule
