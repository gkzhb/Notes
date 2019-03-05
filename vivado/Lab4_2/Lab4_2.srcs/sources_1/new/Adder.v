`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/12/2018 11:25:33 PM
// Design Name: 
// Module Name: Adder
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


module Adder(
    input [3:0] in1,
    input [3:0] in2,
    input Cin,
    output [3:0] out,
    output Co
    );
    
    wire [3:1] cr;
    
    FullAdder a(in1[0], in2[0], Cin, out[0], cr[1]),
              b(in1[1], in2[1], cr[1], out[1], cr[2]),
              c(in1[2], in2[2], cr[2], out[2], cr[3]),
              d(in1[3], in2[3], cr[3], out[3], Co);
    
endmodule
