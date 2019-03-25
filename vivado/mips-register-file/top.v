`timescale 1ns / 1ps

module top(
	input CLK, Reset,
	output [31:0] WriteData, DataAddr,
	output MemWrite,
	input [4:0] ReadReg,
	input [5:0] ReadMem,
	output [31:0] RegData, MemData, outPC);

	wire [31:0] PC, Instr, ReadData;
	assign outPC = PC;

	mips mipscpu(CLK, Reset, PC, Instr, MemWrite, DataAddr, WriteData, ReadData, ReadReg, RegData);
	imem imemory(PC[7:2], Instr);
	dmem dmemory(CLK, MemWrite, DataAddr, WriteData, ReadData, ReadMem, MemData);
endmodule
