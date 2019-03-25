`timescale 1ns / 1ps

module imem(
	input [5:0] A,
	output reg [31:0] RD);
// Instruction Memory ???????????????

	reg [31:0] RAM[63:0];

//	initial
//		$readmemh("/home/zhb/vivado/mips-register-file/memfile.dat", RAM);

	always @(*)
		case (A)
			5'b0_0000: RD <= 32'h20020005;
			5'b0_0001: RD <= 32'h2003000c;
			5'b0_0010: RD <= 32'h2067fff7;
			5'b0_0011: RD <= 32'h00e22025;
			5'b0_0100: RD <= 32'h00642824;
			5'b0_0101: RD <= 32'h00a42820;
			5'b0_0110: RD <= 32'h10a7000a;
			5'b0_0111: RD <= 32'h0064202a;
			5'b0_1000: RD <= 32'h10800001;
			5'b0_1001: RD <= 32'h20050000;
			5'b0_1010: RD <= 32'h00e2202a;
			5'b0_1011: RD <= 32'h00853820;
			5'b0_1100: RD <= 32'h00e23822;
			5'b0_1101: RD <= 32'hac670044;
			5'b0_1110: RD <= 32'h8c020050;
			5'b0_1111: RD <= 32'h08000011;
			5'b1_0000: RD <= 32'h20020001;
			5'b1_0001: RD <= 32'hac020054;
			default: RD <= 32'b0;
		endcase

	// assign RD = RAM[A];
endmodule
