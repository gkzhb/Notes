`timescale 1ns / 1ps

module decode2to4 #(WIDTH = 1)
	(input [WIDTH - 1:0] Data,
	input [1:0] S,
	output reg [WIDTH - 1:0] Y0,
	output reg [WIDTH - 1:0] Y1,
	output reg [WIDTH - 1:0] Y2,
	output reg [WIDTH - 1:0] Y3);

	always @(*)
		case (S)
			2'b00:
			begin
				Y0 <= Data;
				Y1 <= 0;
				Y2 <= 0;
				Y3 <= 0;
			end
			2'b01:
			begin
				Y1 <= Data;
				Y0 <= 0;
				Y2 <= 0;
				Y3 <= 0;
			end
			2'b10:
			begin
				Y2 <= Data;
				Y1 <= 0;
				Y0 <= 0;
				Y3 <= 0;
			end
			2'b11:
			begin
				Y3 <= Data;
				Y1 <= 0;
				Y2 <= 0;
				Y0 <= 0;
			end
			default:
			begin
				Y0 <= 0;
				Y1 <= 0;
				Y2 <= 0;
				Y3 <= 0;
			end
		endcase

endmodule
