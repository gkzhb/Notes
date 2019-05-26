`timescale 1ns / 1ps

module dmem(
	input CLK, Reset, WE,
	input [31:0] A, WD,
	output [31:0] RD,
	input [5:0] ReadAddr,
	output [31:0] Data);
// Data Memory

	reg [31:0] RAM[63:0];
	assign RD = RAM[A[31:2]];
	assign Data = RAM[ReadAddr];

	always @(posedge CLK, posedge Reset)
		if (Reset)
			$readmemh("/home/zhb/vivado/mips-pipeline/clear.dat", RAM);
		else
			if (WE)
				RAM[A[31:2]] <= WD;
			else
				RAM[A[31:2]] <= RAM[A[31:2]];
endmodule
