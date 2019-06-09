`timescale 1ns / 1ps

module maindec(
	input [5:0] Op,
	output MemToReg, MemWrite,
	output Branch, AluSrc,
	output RegDst, RegWrite,
	output Jump,
	output [2:0] AluOp,
	output Bne, ExtOp, RType, DEn);

	reg [12:0] ctls;
	assign {Bne, ExtOp, RegWrite, RegDst, AluSrc, Branch, MemWrite, MemToReg, Jump, AluOp, DEn} = ctls;
	assign RType = ~(|Op);

	always @(*)
		case(Op)
			6'b000_000: ctls <= 13'b0011_0000_00110;	// R-Type
			6'b001_000: ctls <= 13'b0110_1000_00100; // addi
			6'b001_100: ctls <= 13'b0010_1000_00000; // andi
			6'b000_100: ctls <= 13'b0100_0100_01100; // beq
			6'b000_101: ctls <= 13'b1100_0100_01100; // bne
			6'b100_011: ctls <= 13'b0110_1001_00101; // lw
			6'b101_011: ctls <= 13'b0100_1010_00101; // sw
			6'b001_010: ctls <= 13'b0110_1000_01110; // slti
			6'b001_101: ctls <= 13'b0010_1000_00010; // ori
			6'b000_010: ctls <= 13'b0000_0000_10000; // j
			default: ctls <= 12'bxxxx_xxxx_xxxxx; //Illegal Op
		endcase
endmodule
