`timescale 1ns / 1ps

module mips(
	input CLK, Reset,
	input [31:0] MemData,
	output MemWrite,
	output [31:0] Addr, WriteData, PC,
	input [4:0] DispReadReg,
	output [31:0] DispRegData, PCNext, Instr,
	output [3:0] Stat);

	wire [5:0] Op, Funct;
	wire Zero, IorD, IRWrite, RegDst, MemToReg, ALUSrcA, RegWrite, PCEn, ExtOp;
	wire [2:0] ALUCtl;
	wire [1:0] ALUSrcB, PCSrc;

	controller c(CLK, Reset, Op, Funct, Zero, IorD, MemWrite, IRWrite, RegDst, MemToReg, ALUSrcA, RegWrite, PCEn, ExtOp, ALUSrcB, PCSrc, ALUCtl, Stat);
	datapath dp(CLK, Reset, MemData, IorD, IRWrite, RegDst, MemToReg, ALUSrcA, RegWrite, PCEn, ExtOp, ALUCtl, ALUSrcB, PCSrc, Addr, PCNext, WriteData, Instr, Op, Funct, Zero, PC, DispReadReg, DispRegData);

endmodule
