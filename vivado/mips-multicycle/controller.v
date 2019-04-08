`timescale 1ns / 1ps

module controller(
	input CLK, Reset,
	input [5:0] Op,
	output IorD);

	// FSM State Encode
	parameter FETCH   = 4'b0000;	// Fetch instruction
	parameter DECODE  = 4'b0001;	// Decode
	parameter MEMADR  = 4'b0010;	// Calculate memory address
	parameter MEMRD   = 4'b0011;	// LW: Memory read
	parameter MEMWB   = 4'b0100;	// LW: Memory write back to reg
	parameter MEMWR   = 4'b0101;	// SW: Memory write
	parameter RTYPEEX = 4'b0110;	// R-Type: Execute
	parameter RTYPEWB = 4'b0111;	// R-Type: Write back to reg
	parameter BEX     = 4'b1000;	// BEQ & BNE
	parameter ITYPEEX = 4'b1001;	// I-Type: Execute
	parameter ITYPEWB = 4'b1010;	// I-Type: Write back to reg
	parameter JEX     = 4'b1011;	// Jump: Execute
	parameter TMP     = 4'b1100;	// None

	// Op Code
	parameter LW    = 6'b10_0011;
	parameter RTYPE = 6'b00_0000;

endmodule
