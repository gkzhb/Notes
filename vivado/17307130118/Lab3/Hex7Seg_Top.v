`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/07/2018 06:57:16 PM
// Design Name: 
// Module Name: Hex7Seg_Top
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


module Hex7Seg_Top(
    input [15:0] SW,
    input BTNC,
    input CLK100MHZ,
    output CG,
    output CF,
    output CE,
    output CD,
    output CC,
    output CB,
    output CA,
    output [3:0] AN,// 使能
    output DP       // 小数点
    );
    
    wire [6:0] a2g;
    
    assign a2g = {CG, CF, CE, CD, CC, CB, CA};
    
    async7seg (.x(SW),
               .clk(CLK100MHZ),
               .clr(BTNC),
               .a2g(a2g),
               .an(AN),
               .dp(DP)); 
    
endmodule
