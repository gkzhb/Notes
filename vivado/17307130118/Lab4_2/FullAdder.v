`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/12/2018 06:09:38 PM
// Design Name: 
// Module Name: FullAdder
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


module FullAdder(
    input A, B, Cin,
    output S, Co
    );
    
    wire [2:0] in;
    wire [2:0] nin;
    wire [3:0] out1;
    wire [2:0] out2;
    assign in = {A, B, Cin};
    assign nin = ~in[2:0];
    
    nand na1(out1[0], nin[0], nin[1], nin[2]),
         na2(out1[1], nin[0], in[1], in[2]),
         na3(out1[2], in[0], in[1], nin[2]),
         na4(out1[3], in[0], nin[1], in[2]),
         na5(out2[0], nin[0], nin[1]),
         na6(out2[1], nin[0], nin[2]),
         na7(out2[2], nin[1], nin[2]);
    assign S = & out1;
    assign Co = & out2;    
    
endmodule
