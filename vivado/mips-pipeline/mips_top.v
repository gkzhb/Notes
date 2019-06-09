`timescale 1ns / 1ps

module mips_top(
	input CLK, Reset,
	output [31:0] PC, PCNext,
	input [4:0] DispReadReg,
	input [6:0] DispReadMem,
	output [31:0] DispRegData, DispMemData, Instr,
	output cpuclk, ready, iHit, dHit,
	output [3:0] istate, dstate);

	wire [31:0] dataAddr, writeData, readData;
	wire memWrite;

	reg state, nextstate;

	wire cpumask, suspense, iEn, dEn, iMWE, dMWE, iMReady, dMReady;
	wire [31:0] iMAddr, dMAddr, iMWD, dMWD, iMRD, dMRD;

	mips mipscore(cpuclk, Reset, PC, Instr, memWrite, dataAddr, writeData, readData, PCNext, DispReadReg, DispRegData, iEn, dEn);

	imem instruction_memory(CLK, Reset, iMAddr, iMReady, iMRD);
	dmem data_memory(CLK, Reset, dMWE, dMAddr, dMWD, dMReady, dMRD, DispReadMem, DispMemData);

	cache instr_cache(CLK, Reset, iEn, suspense, PC, 1'b0, 32'b0, iHit, Instr,
						iMAddr, iMWE, iMWD, iMReady, iMRD, istate);
	cache  data_cache(CLK, Reset, dEn, suspense, dataAddr, memWrite, writeData, dHit, readData,
						dMAddr, dMWE, dMWD, dMReady, dMRD, dstate);

	assign ready = (~iEn | iHit) & (~dEn | dHit);
	assign cpuclk = cpumask & CLK;
	assign cpumask = ready & state;
	assign suspense = ~ready;

	always @(*)
		if (Reset)
			nextstate = 1'b0;
		else
			nextstate = ready;

	always @(posedge CLK)
		if (Reset)
			state <= 2'b00;
		else
			state <= nextstate;
	
endmodule
