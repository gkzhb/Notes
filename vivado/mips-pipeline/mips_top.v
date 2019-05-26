`timescale 1ns / 1ps

module mips_top(
	input CLK, Reset,
	output [31:0] PC, PCNext,
	input [4:0] DispReadReg,
	input [5:0] DispReadMem,
	output [31:0] DispRegData, DispMemData);

	wire [31:0] instr, dataAddr, writeData, readData;
	wire memWrite;

	mips mipscore(CLK, Reset, PC, instr, memWrite, dataAddr, writeData, readData, PCNext, DispReadReg, DispRegData);
	imem instruction_memory(PC[7:2], instr);
	dmem data_memory(CLK, Reset, memWrite, dataAddr, writeData, readData, DispReadMem, DispMemData);

endmodule
