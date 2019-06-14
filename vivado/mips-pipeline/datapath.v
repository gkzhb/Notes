`timescale 1ns / 1ps

module datapath(
	input CLK, Reset,
	input MemToRegE, MemToRegM, MemToRegW,
	input PCSrcD, BranchD,
	input ALUSrcE, RegDstE,
	input RegWriteE, RegWriteM, RegWriteW,
	input ExtOpD, JumpD,
	input [2:0] ALUCtlE,
	output EqualD,
	output [31:0] PCF,
	input [31:0] InstrF,
	output [31:0] ALUOutM, WriteDataM,
	input [31:0] ReadDataM,
	output [5:0] OpD, FunctD,
	output FlushE,
	output [31:0] PCNext,
	input [4:0] DispReadReg,
	output [31:0] DispRegData);

	assign PCNext = pcNextFD;

	wire forwardaD, forwardbD;
	wire [1:0] forwardaE, forwardbE;
	wire stallF;
	wire [4:0] rsD, rtD, rdD, rsE, rtE, rdE;
	wire [4:0] writeRegE, writeRegM, writeRegW;
	wire flushD;
	wire [31:0] pcNextFD, pcNextBrFD, pcPlus4F, pcBranchD;
	wire [31:0] signImmD, signImmE, signImmShD;
	wire [31:0] srcAD, srcA2D, srcAE, srcA2E;
	wire [31:0] srcBD, srcB2D, srcBE, srcB2E, srcB3E;
	wire [31:0] pcPlus4D, instrD;
	wire [31:0] aluOutE, aluOutW;
	wire [31:0] readDataW, resultW;
	wire zero;

	hazard h(rsD, rtD, rsE, rtE, writeRegE, writeRegM, writeRegW,
			RegWriteE, RegWriteM, RegWriteW,
			MemToRegE, MemToRegM, BranchD,
			forwardaD, forwardbD, forwardaE, forwardbE,
			stallF, stallD, FlushE);

	mux2 #(32) pcbrmux(pcPlus4F, pcBranchD, PCSrcD, pcNextBrFD);
	mux2 #(32) pcmux(pcNextBrFD, {pcPlus4D[31:28], instrD[25:0], 2'b00},
					JumpD, pcNextFD);

	regfile rf(CLK, Reset, RegWriteW, rsD, rtD, writeRegW,
				resultW, srcAD, srcBD, DispReadReg, DispRegData);

	// Fetch
	flopenr #(32) pcreg(CLK, Reset, ~stallF, pcNextFD, PCF);
	adder pcadd1(PCF, 32'b100, pcPlus4F);

	// Decode
	flopenr #(32) r1D(CLK, Reset, ~stallD, pcPlus4F, pcPlus4D);
	flopenrc #(32) r2D(CLK, Reset, flushD, ~stallD, InstrF, instrD);
	ext se(instrD[15:0], ExtOpD, signImmD);
	sl2 immsh(signImmD, signImmShD);
	adder pcadd2(pcPlus4D, signImmShD, pcBranchD);
	mux2 #(32) forwardadmux(srcAD, ALUOutM, forwardaD, srcA2D);
	mux2 #(32) forwardbdmux(srcBD, ALUOutM, forwardbD, srcB2D);
	equalcmp comp(srcA2D, srcB2D, EqualD);
	assign OpD = instrD[31:26];
	assign FunctD = instrD[5:0];
	assign rsD = instrD[25:21];
	assign rtD = instrD[20:16];
	assign rdD = instrD[15:11];

	assign flushD = (PCSrcD | JumpD) & ~stallD; // Edited when debugging cache

	// Execute
	floprc #(32) r1E(CLK, Reset, FlushE, srcAD, srcAE);
	floprc #(32) r2E(CLK, Reset, FlushE, srcBD, srcBE);
	floprc #(32) r3E(CLK, Reset, FlushE, signImmD, signImmE);
	floprc #(5) r4E(CLK, Reset, FlushE, rsD, rsE);
	floprc #(5) r5E(CLK, Reset, FlushE, rtD, rtE);
	floprc #(5) r6E(CLK, Reset, FlushE, rdD, rdE);
	mux4 #(32) forwardaemux(srcAE, resultW, ALUOutM, 32'b0, forwardaE, srcA2E);
	mux4 #(32) forwardbemux(srcBE, resultW, ALUOutM, 32'b0, forwardbE, srcB2E);
	mux2 #(32) srcbmux(srcB2E, signImmE, ALUSrcE, srcB3E);
	ALU alu(srcA2E, srcB3E, ALUCtlE, aluOutE, zero);
	mux2 #(5) wrmux(rtE, rdE, RegDstE, writeRegE);

	// Memory
	flopr #(32) r1M(CLK, Reset, srcB2E, WriteDataM);
	flopr #(32) r2M(CLK, Reset, aluOutE, ALUOutM);
	flopr #(5) r3M(CLK, Reset, writeRegE, writeRegM);
	
	// Writeback
	flopr #(32) r1W(CLK, Reset, ALUOutM, aluOutW);
	flopr #(32) r2W(CLK, Reset, ReadDataM, readDataW);
	flopr #(5) r3W(CLK, Reset, writeRegM, writeRegW);
	mux2 #(32) resmux(aluOutW, readDataW, MemToRegW, resultW);

endmodule
