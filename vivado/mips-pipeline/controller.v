`timescale 1ns / 1ps

module controller(
	input CLK, Reset,
	input [5:0] OpD, FunctD,
	input FlushE, EqualD,
	output MemToRegE, MemToRegM, MemToRegW, MemWriteM,
	output PCSrcD, BranchD, ALUSrcE,
	output RegDstE, RegWriteE, RegWriteM, RegWriteW,
	output JumpD,
	output [2:0] ALUCtlE);

	wire [2:0] aluOpD, aluCtlD;

	wire memToRegD, memWriteD, aluSrcD, regDstD, regWriteD, memWriteE;

endmodule
