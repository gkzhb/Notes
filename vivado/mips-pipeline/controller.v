`timescale 1ns / 1ps

module controller(
	input CLK, Reset,
	input [5:0] OpD, FunctD,
	input FlushE, EqualD,
 	output MemToRegE, MemToRegM, MemToRegW, MemWriteM,
 	output PCSrcD, BranchD, ALUSrcE,
	output RegDstE, RegWriteE, RegWriteM, RegWriteW,
 	output ExtOpD, JumpD,
 	output [2:0] ALUCtlE);

	wire [2:0] aluOpD0, aluOpD1, aluCtlD;

	wire memToRegD, memWriteD, aluSrcD, regDstD, regWriteD, memWriteE, bneD, ExtOpD, rTypeD;

	maindec md(OpD[5:0], memToRegD, memWriteD, BranchD, aluSrcD, regDstD, regWriteD, JumpD, aluOpD0[2:0], bneD, ExtOpD, rTypeD);
	aludec ad(FunctD[5:0], aluOpD1[2:0]);
	mux2 #(3) muxaluop(aluOpD0[2:0], aluOpD1[2:0], rTypeD, aluCtlD[2:0]);

	assign PCSrcD = BranchD & (bneD ^ EqualD);

	floprc #(8) regE(CLK, Reset, FlushE,
				{memToRegD, memWriteD, aluSrcD, regDstD, regWriteD, aluCtlD},
				{MemToRegE, memWriteE, ALUSrcE, RegDstE, RegWriteE, ALUCtlE});
	flopr #(3) regM(CLK, Reset,
				{MemToRegE, memWriteE, RegWriteE},
				{MemToRegM, MemWriteM, RegWriteM});
	flopr #(2) regW(CLK, Reset,
				{MemToRegM, RegWriteM},
				{MemToRegW, RegWriteW});

endmodule
