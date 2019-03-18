`timescale 1ns / 1ps

module imem(
	input [5:0] A,
	output [31:0] RD);
// Instruction Memory 指令存储器

	reg [31:0] RAM[63:0];

	initial
		$readmemh("memfile.dat", RAM);

	assign RD = RAM[A];
endmodule
