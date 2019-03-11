`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/11/2019 04:35:11 PM
// Design Name: 
// Module Name: ALU_test
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module ALU_test();
	reg clk;
	reg [31:0] A, B;
	reg [2:0] Alucont;
	wire [31:0] Result;
	wire Zero;

	ALU alu(.A(A), .B(B), .Alucont(Alucont), .Result(Result), .Zero(Zero));

	parameter PERIOD = 10;

	always begin
		clk = 1'b0;
		#(PERIOD/2) clk = 1'b1;
		#(PERIOD/2);
	end

	initial begin
		clk = 1'b0;
		A = 32'b1111;
		B = 32'b1110;
		Alucont = 3'b000;
		#100;
		Alucont = 3'b010;
		#100;
		Alucont = 3'b011;
		#100;
		Alucont = 3'b110;
		#100;
		Alucont = 3'b111;
		#100;
		A = 32'b1000_0000_0000_0000_0000_0000_0000_0000;
		B = 32'b1000_0000_0000_0000_0000_0000_0000_0000;
		#100;
		A = 32'b1100;
		B = 32'b1111;
	end

endmodule
