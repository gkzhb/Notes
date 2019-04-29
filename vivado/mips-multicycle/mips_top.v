`timescale 1ns / 1ps

module mips_top(
	input CLK, Reset,
	output [31:0] PC,
	input [4:0] DispReadReg,
	input [5:0] DispReadMem,
	output [31:0] DispRegData, DispMemData, PCNext, Instr,
	output [3:0] Stat);

	wire [31:0] MemData, Addr, WriteData;
	wire MemWrite;

	mips mipscpu(CLK, Reset, MemData, MemWrite, Addr, WriteData, PC, DispReadReg, DispRegData, PCNext, Instr, Stat);
	mem memory(CLK, MemWrite, Addr, WriteData, MemData, DispReadMem, DispMemData);
endmodule
