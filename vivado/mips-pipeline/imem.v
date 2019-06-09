`timescale 1ns / 1ps

module imem(
	input CLK, Reset,
	input [31:0] A,
	output reg Ready,
	output reg [31:0] RD);
// Instruction Memory 指令内存

	reg [31:0] RAM[63:0];

	initial
		// $readmemh("/home/zhb/vivado/mips-pipeline/memfile.dat", RAM);
		$readmemh("/home/zhb/vivado/mips-pipeline/run1.dat", RAM);

	// assign RD = RAM[A];


	reg [1:0] state;
	wire [1:0] nextstate;

	assign nextstate = state + 1;

	always @(posedge CLK)
		if (Reset)
			state <= 2'b00;
		else
			state <= nextstate;

	always @(*)
		if (state == 2'b11)
		begin
			Ready <= 1'b1;
			RD <= RAM[A[7:2]];
		end
		else
		begin
			Ready <= 1'b0;
			RD <= 32'b0;
		end

endmodule
