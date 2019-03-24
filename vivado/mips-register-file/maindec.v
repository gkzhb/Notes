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
			6'b000_000: ctls <= 12'bxx11_0000_0010;	// R-Type
			6'b001_000: ctls <= 12'bx110_1000_0010; // addi
			6'b001_100: ctls <= 12'bx010_1000_0000; // andi
			6'b000_100: ctls <= 12'b010x_010x_0110; // beq
			6'b000_101: ctls <= 12'b110x_010x_0110; // bne
			6'b100_011: ctls <= 12'bx110_1001_0010; // lw
			6'b101_011: ctls <= 12'bx10x_101x_0010; // sw
			6'b001_010: ctls <= 12'bx110_1000_0111; // slti
			6'b001_101: ctls <= 12'bx010_1000_0001; // ori
			6'b000_010: ctls <= 12'bxx0x_x00x_1xxx; // j
			default: ctls <= 12'bxxxx_xxxx_xxxx; //Illegal Op
		endcase
endmodule
