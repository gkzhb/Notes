`timescale 1ns / 1ps

module mips_top(
	input CLK, Reset,
	output PC,
	input [4:0] DispReadReg,
	input [5:0] DispReadMem,
	output [31:0] DispRegData, DispMemData, PCNext);

	wire [31:0] Instr, MemData, Addr, WriteData;
	wire MemWrite;

	mips mipscpu(CLK, Reset, Instr, MemData, MemWrite, Addr, WriteData, PC, DisReadReg, DispRegData, PCNext);
	mem memory(CLK, MemWrite, Addr, WriteData, MemData, DispReadMem, DispMemData);
endmodule
