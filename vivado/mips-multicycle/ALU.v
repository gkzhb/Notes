`timescale 1ns / 1ps

module ALU(
	input [31:0] A,
	input [31:0] B,
	input [2:0] Alucont,
	output reg [31:0] Result,
	output Zero
	);

	wire [31:0] add, sub;

	assign Zero = ~(| Result);
	assign add = A + B;
	assign sub = A + (~B + 1);

	always @(*)
	begin
		case(Alucont)
			3'b000: Result <= A & B;
			3'b001: Result <= A | B;
			3'b010: Result <= add;
			3'b100: Result <= A & (~B);
			3'b101: Result <= A | (~B);
			3'b110: Result <= sub;
			3'b111: Result <= {31'b000_0000_0000_0000_0000_0000_0000_0000, sub[31]};
			3'b011: Result <= 31'b0;
			default: Result <= 31'b0;
		endcase
	end

endmodule 
