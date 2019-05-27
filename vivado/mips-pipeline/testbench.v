`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/03/24 20:30:42
// Design Name: 
// Module Name: testbench
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


module testbench();

	reg CLK, Reset;
	wire [31:0] PC, DispReg, DispMem, PCNext;
	reg [5:0] Disp;
	mips_top dut(CLK, Reset, PC, PCNext, Disp[4:0], Disp, DispReg, DispMem);

	initial
	begin
		Disp <= 5'b10;
		Reset <= 1; #5; Reset <= 0;
	end

	always
	begin
		CLK <= 1; #5; CLK <= 0; #5;
	end

	// always @(negedge CLK)
	// begin
	// 	if (MemWrite) begin
	// 		if (DataAddr === 84 & WriteData === 7) begin
	// 			$display("Simulation succeeded");
	// 			$stop;
	// 		end else if (DataAddr !== 80) begin
	// 			$display("Simulation failed");
	// 			$stop;
	// 		end
	// 	end
	// end
	
endmodule
