`timescale 1ns / 1ps

module regfile(
	input CLK,
	input WE3,
	input [4:0] RA1, RA2, RA3,
	input [31:0] WD3,
	output [31:0] RD1, RD2,
	input [4:0] RA4,
	output [31:0] RD4);

	reg [31:0] rf [31:0];

	always @(posedge CLK)
		if (WE3)
			rf[RA3] <= WD3;
		else
			rf[RA3] <= rf[RA3];
	
	assign RD1 = (RA1 != 0) ? rf[RA1] : 0;
	assign RD2 = (RA2 != 0) ? rf[RA2] : 0;
	assign RD4 = (RA4 != 0) ? rf[RA4] : 0;
endmodule
