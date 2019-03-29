`timescale 1ns / 1ps

module imem(
	input [5:0] A,
	output reg [31:0] RD);
// Instruction Memory 指令内存

	reg [31:0] RAM[63:0];

	// initial
		// $readmemh("/home/zhb/vivado/mips-register-file/memfile.dat", RAM);

	always @(*)
		case (A)
			6'b00_0000: RD <= 32'h20020005;
			6'b00_0001: RD <= 32'h2003000c;
			6'b00_0010: RD <= 32'h2067fff7;
			6'b00_0011: RD <= 32'h00e22025;
			6'b00_0100: RD <= 32'h00642824;
			6'b00_0101: RD <= 32'h00a42820;
			6'b00_0110: RD <= 32'h10a7000a;
			6'b00_0111: RD <= 32'h0064202a;
			6'b00_1000: RD <= 32'h10800001;
			6'b00_1001: RD <= 32'h20050000;
			6'b00_1010: RD <= 32'h00e2202a;
			6'b00_1011: RD <= 32'h00853820;
			6'b00_1100: RD <= 32'h00e23822;
			6'b00_1101: RD <= 32'hac670044;
			6'b00_1110: RD <= 32'h8c020050;
			6'b00_1111: RD <= 32'h08000011;
			6'b01_0000: RD <= 32'h20020001;
			6'b01_0001: RD <= 32'hac020054;
			default: RD <= 32'b0;
		endcase

	// assign RD = RAM[A];
endmodule
