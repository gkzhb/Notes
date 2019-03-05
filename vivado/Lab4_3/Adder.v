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
    
    wire [4:0] cr;
    wire [3:0] P, G;
    FullAdder2(in1[0], in2[0], cr[0], out[0], P[0], G[0]);
    FullAdder2(in1[1], in2[1], cr[1], out[1], P[1], G[1]);
    FullAdder2(in1[2], in2[2], cr[2], out[2], P[2], G[2]);
    FullAdder2(in1[3], in2[3], cr[3], out[3], P[3], G[3]);
//    assign P = in1 ^ in2;
//    assign G = in1 & in2;
    assign cr[0] = Cin;
    assign Co = cr[4];
    assign cr[1] = G[0] | (P[0] & Cin);
    assign cr[2] = G[1] | (P[1] & G[0]) | (P[1] & P[0] & Cin);
    assign cr[3] = G[2] | (P[2] & G[1]) | (P[2] & P[1] & G[0]) | (P[2] & P[1] & P[0] & Cin);
    assign cr[4] = G[3] | (P[3] & G[2]) | (P[3] & P[2] & G[1]) | (P[3] & P[2] & P[1] & G[0]) | (P[3] & P[2] & P[1] & P[0] & Cin);
    assign out = P ^ cr;
    
endmodule
