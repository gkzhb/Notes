`timescale 1ns / 1ps

module datapath(
	input CLK, Reset,
	input [31:0] MemData,
	input IorD, MemWrite, IRWrite, RegDst, MemToReg, ALUSrcA, RegWrite, PCEn,
	input ExtOp,
	input [2:0] ALUCtl,
	input [1:0] ALUSrcB, PCSrc,
	output [31:0] Addr, PCNext, WriteData,
	output [5:0] Op, Funct,
	output Zero,
	input [4:0] DispReadReg,
	output [31:0] DispRegData);
	
	wire [31:0] Instr, Data, SignImm, SignImmsh;
	wire [31:0] rd1, SrcA, SrcB, ALUResult, ALUOut;
	wire [31:0] PC, PCNext;
	wire [4:0] WriteReg;

	// PC
	enreg #(32) pcreg(CLK, Reset, PCEn, PCNext, PC);
	mux4 #(32) pcmux(ALUResult, ALUOut, {PC[31:28], Instr[25:0], 2'b00}, 32'b0, PCSrc, PCNext);
	mux2 #(32) addrmux(PC, ALUOut, IorD, Addr);

	// regfile
	regfile rf(CLK, RegWrite, Instr[25:21], Instr[20:16], WriteReg, Result, rd1, WriteData, DispReadReg[4:0], DispRegData);
	mux2 #(5) wrmux(Instr[20:16], Instr[15:11], RegDst, WriteReg);
	mux2 #(32) resmux(ALUOut, Data, MemToReg, Result);

	// Instr
	enreg #(32) instrreg(CLK, Reset, IRWrite, MemData, Instr);
	flopr #(32) DataStore(CLK, Reset, MemData, Data);

	// ALU
	ext se(Instr[15:0], ExtOp, SignImm);
	sl2 immsh(SignImm, SignImmsh);
	mux2 #(32) srcamux(PC, rd1, ALUSrcA, SrcA);
	mux4 #(32) srcbmux(SrcB, 32'b100, SignImm, SignImmsh, ALUSrcB, SrcB);
	ALU alu(SrcA, SrcB, ALUCtl, ALUResult, Zero);
	flopr #(32) alustore(CLK, Reset, ALUResult, ALUOut);

endmodule
