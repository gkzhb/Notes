`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/01/2018 10:46:54 PM
// Design Name: 
// Module Name: decode3to8
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

module decode4to16(
    output wire [15:0] Y,
    input wire [3:0] S
    );

    wire nS;
    wire [1:0] G2;
    not (nS, S[3]);
    assign G2 = 2'b0;
    decode4to16 low(Y[7:0], S[2:0], nS, G2),
                high(Y[15:8], S[2:0], S[3], G2);
endmodule

module decode3to8(
    output wire [7:0] Y,
    input wire [2:0] S,
    input wire G1,
    input wire [1:0] G2
    );
    
    wire flag;
    wire [7:0] temp;
    wire nS;
    //reg [7:0] a;
    
    assign flag = (~G1) | (| G2);
    not (nS, S[2]);
    
    decode2to4 high(temp[7:4], S[1:0], S[2]),
               low(temp[3:0], S[1:0], nS);
    //always @(temp)
        //a <= temp;
    
    assign Y[7:0] = ~temp[7:0] | {8{flag}};
    
endmodule

module decode2to4(
    output wire [3:0] Y,
    input wire [1:0] S,
    input wire G1
    );
    
    assign Y[0] = G1 & ~(|S);
    assign Y[1] = G1 & S[0] & (~S[1]);
    assign Y[2] = G1 & (~S[0]) & S[1]; 
    assign Y[3] = G1 & (&S);
endmodule