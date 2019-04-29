`timescale 1ns / 1ps

module aludec(
	input [5:0] Op, Funct,
	output reg [2:0] AluCtl,
	output reg ExtOp);

	wire itype;
	assign itype = |Op;

	always @(*)
		if (itype)
			case(Op)	// I-Type or others
				6'b001_000: AluCtl = 010;	// addi
				6'b001_100: AluCtl = 000;	// andi
				6'b001_010: AluCtl = 111;	// slti
				6'b001_101: AluCtl = 001;	// ori
				default: AluCtl = 3'b000;	// others
			endcase
		else
			case(Funct)	// R-Type
				6'b100_000: AluCtl = 3'b010;	// add
				6'b100_100: AluCtl = 3'b000;	// and
				6'b100_101: AluCtl = 3'b001;	// or
				6'b101_010: AluCtl = 3'b111;	// slt
				6'b100_010: AluCtl = 3'b110;	// sub
				6'b000_000: AluCtl = 3'b000;	// nop
				default: AluCtl = 3'b000;
			  endcase
	always @(*)
		case(Op)
			6'b001_000: ExtOp = 1;	// addi
			6'b001_100: ExtOp = 0;	// andi
			6'b001_010: ExtOp = 1;	// slti
			6'b001_101: ExtOp = 0;	// ori
			default: ExtOp = 1;		// others
		endcase

endmodule
