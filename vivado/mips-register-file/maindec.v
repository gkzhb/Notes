`timescale 1ns / 1ps

module maindec(
	input [5:0] Op,
	output MemToReg, MemWrite,
	output Branch, AluSrc,
	output RegDst, RegWrite,
	output Jump,
	output [2:0] AluOp,
	output Bne, ExtOp);

	reg [12:0] ctls;
	assign {Bne, ExtOp, RegWrite, RegDst, AluSrc, Branch, MemWrite, MemToReg, Jump, AluOp} = ctls;

	always @(*)
		case(Op)
			6'b000_000: ctls <= 12'b0011_0000_0011;	// R-Type
			6'b001_000: ctls <= 12'b0110_1000_0010; // addi
			6'b001_100: ctls <= 12'b0010_1000_0000; // andi
			6'b000_100: ctls <= 12'b0100_0100_0110; // beq
			6'b000_101: ctls <= 12'b1100_0100_0110; // bne
			6'b100_011: ctls <= 12'b0110_1001_0010; // lw
			6'b101_011: ctls <= 12'b0100_1010_0010; // sw
			6'b001_010: ctls <= 12'b0110_1000_0111; // slti
			6'b001_101: ctls <= 12'b0010_1000_0001; // ori
			6'b000_010: ctls <= 12'b0000_0000_1000; // j
			default: ctls <= 12'bxxxx_xxxx_xxxx; //Illegal Op
		endcase
endmodule
