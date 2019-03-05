`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/29/2018 10:54:58 PM
// Design Name: 
// Module Name: Clock_Top
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


module Clock_Top(
    input CLK100MHZ,
    input [2:0] SW,
    output CG, CF, CE, CD, CC, CB, CA,
    output [7:0] AN,
    output DP
    );
    
    assign AN[7:4] = 4'b1111;
    Clock(CLK100MHZ, SW[0], SW[1], SW[2], {CG, CF, CE, CD, CC, CB, CA}, AN[3:0], DP);
endmodule
