`timescale 1ns / 1ps

module mux4 #(parameter WIDTH=8)
	(input [WIDTH * 4 - 1:0] D,
	input [1:0] S,
	output [WIDTH - 1:0] Y);

	always @(*)
		case S:
			2'b00: Y <= D[WIDTH * 4 - 1, WIDTH * 3];
			2'b01: Y <= D[WIDTH * 3 - 1, WIDTH * 2];
			2'b10: Y <= D[WIDTH  * 2 - 1, WIDTH];
			2'b11: Y <= D[WIDTH - 1, 0];
			default: Y <= WIDTH'b0;
		endcase
endmodule
