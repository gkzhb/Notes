`timescale 1ns / 1ps

module aludec(
	input [5:0] Funct,
	output reg [2:0] AluCtl);

	always @(*)
		case(Funct)	// R-type
			6'b100_000: AluCtl <= 3'b010;	// add
			6'b100_100: AluCtl <= 3'b000;	// and
			6'b100_101: AluCtl <= 3'b001;	// or
			6'b101_010: AluCtl <= 3'b111;	// slt
			6'b100_010: AluCtl <= 3'b110;	// sub
			6'b000_000: AluCtl <= 3'b000;	// nop
			default: AluCtl <= 3'bxxx;
		  endcase
endmodule
