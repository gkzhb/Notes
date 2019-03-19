`timescale 1ns / 1ps

module aludec(
	input [5:0] Funct,
	input [1:0] AluOp,
	output [2:0] AluCtl);

	always @(*)
		case(AluOp)
			2'b00: AluCtl <= 3'b
			// TODO
			default: case(Funct)	// R-type
				6'b1000_00: AluCtl <= 3'b
				default: AluCtl <= 3'bxxx;
			  endcase
		endcase
endmodule
