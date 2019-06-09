`timescale 1ns / 1ps

module mips(
	input CLK, Reset,
	output [31:0] PCF,
	input [31:0] InstrF,
	output MemWriteM,
	output [31:0] AluOutM, WriteDataM,
	input [31:0] ReadDataM,
	output [31:0] PCNext,
	input [4:0] DispReadReg,
	output [31:0] DispRegData,
	output IEn, DEn);

	wire [5:0] opD, functD;
	wire regDstE, aluSrcE, pcSrcD, memToRegE, memToRegM, memToRegW,
		regWriteE, regWriteM, regWriteW;
	wire [2:0] aluCtlE;
	wire flushE, equalD, extOpD, jumpD;

	controller c(CLK, Reset, opD, functD, flushE, equalD,
				memToRegE, memToRegM, memToRegW, MemWriteM,
				pcSrcD, branchD, aluSrcE, regDstE, regWriteE, regWriteM, regWriteW,
				extOpD, jumpD, aluCtlE, IEn, DEn);
	datapath dp(CLK, Reset, memToRegE, memToRegM, memToRegW, pcSrcD, branchD,
				aluSrcE, regDstE, regWriteE, regWriteM, regWriteW, extOpD, jumpD,
				aluCtlE, equalD, PCF, InstrF, AluOutM, WriteDataM, ReadDataM,
				opD, functD, flushE, PCNext, DispReadReg, DispRegData);

endmodule
