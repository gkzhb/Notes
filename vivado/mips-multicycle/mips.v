`timescale 1ns / 1ps

module mips(
	input CLK, Reset,
	input [31:0] Instr, MemData,
	output MemWrite,
	output [31:0] Addr, WriteData, PC,
	input [4:0] DispReadReg,
	output [31:0] DispRegData, PCNext);

	wire [5:0] Op, Funct;
	wire Zero, IorD, IRWrite, RegDst, MemToReg, ALUSrcA, RegWrite, PCEn, ExtOp;
	wire [2:0] ALUCtl;
	wire [1:0] ALUSrcB, PCSrc;

	controller c(CLK, Reset, Op, Funct, Zero, IorD, MemWrite, IRWrite, RegDst, MemToReg, ALUSrcA, RegWrite, PCEn, ExtOp, ALUCtl, ALUSrcB, PCSrc, ALUCtl);
	datapath dp(CLK, Reset, MemData, IorD, MemWrite, IRWrite, RegDst, MemToReg, ALUSrcA, RegWrite, PCEn, ExtOp, ALUCtl, ALUSrcB, PCSrc, Addr, PCNext, WriteData, Op, Funct, Zero, PC, DispReadReg, DispRegData);

endmodule
