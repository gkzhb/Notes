`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/02/2018 12:43:21 AM
// Design Name: 
// Module Name: decode
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


module decode(
    output wire [3:0] Y,
    input wire [1:0] S,
    input wire G1
);

    assign Y[0] = G1 & ~(|S);
    assign Y[1] = G1 & S[0] & (~S[1]);
    assign Y[2] = G1 & (~S[0]) & S[1]; 
    assign Y[3] = G1 & (&S);

endmodule
