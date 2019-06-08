`timescale 1ns / 1ps

module dmem #(WIDTH = 7)
	(input CLK, Reset, WE,
	input [31:0] A, WD,
	output reg Ready,
	output reg [31:0] RD,
	input [WIDTH - 1:0] ReadAddr,
	output [31:0] Data);
// Data Memory

	reg [31:0] RAM[2**WIDTH - 1:0];
	// assign RD = RAM[A[8:2]];
	assign Data = RAM[ReadAddr];

	reg [1:0] state;
	wire [1:0] nextstate;

	assign nextstate = state + 1;

	integer i;
	always @(posedge CLK)
		if (Reset)
		begin
			state <= 2'b00;
			for (i = 0; i < 2**WIDTH; i = i + 1)
				RAM[i] <= 32'b0;
		end
		else
			state <= nextstate;

	always @(*)
		if (state == 2'b11)
		begin
			Ready <= 1'b1;
			if (WE)
			begin
				RAM[A[WIDTH + 1:2]] <= WD;
				RD <= 32'b0;
			end
			else
			begin
				RAM[A[WIDTH + 1:2]] <= RAM[A[WIDTH + 1:2]];
				RD <= RAM[A[WIDTH + 1:2]];
			end
		end
		else
		begin
			Ready <= 1'b0;
			RAM[A[WIDTH + 1:2]] <= RAM[A[WIDTH + 1:2]];
			RD <= 32'b0;
		end

	/* 
	wire clock;
	integer i;
	always @(posedge CLK, posedge Reset)
		if (Reset)
		begin
			for (i = 0; i < 2**64; i = i + 1)
				RAM[i] <= 32'b0;
			// $readmemh("/home/zhb/vivado/mips-pipeline/clear.dat", RAM);
		end
		else
			if (WE)
				RAM[A[31:2]] <= WD;
			else
				RAM[A[31:2]] <= RAM[A[31:2]];
	*/

endmodule
