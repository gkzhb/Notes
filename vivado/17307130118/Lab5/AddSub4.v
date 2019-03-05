`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/23/2018 08:35:31 AM
// Design Name: 
// Module Name: AddSub4
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


module AddSub4(
    input [3:0] A,
    input [3:0] B,
    input SIGN,
    output [3:0] S,
    output CF,
    output OVF
    );
    
    wire [4:0] c;
    wire [3:0] xorb;
    
    assign xorb = B ^ {4{SIGN}};
    assign c[0] = SIGN;
    assign c[4:1] = A & xorb | c[3:0] & (A ^ xorb);
    assign CF = c[4];
    assign OVF = c[3] ^ c[4];
    assign S = A ^ xorb ^ c[3:0];
endmodule
