`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/22/2018 11:20:10 PM
// Design Name: 
// Module Name: ALU_Top
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


module ALU_Top(
    input [11:0] SW,
    output [7:0] LED
    );
    ALU lab(.A(SW[3:0]), .B(SW[7:4]), .Cn(SW[8]), .M(SW[9]), .S(SW[11:10]),
        .F(LED[3:0]), .Cn4(LED[4]), .NF(LED[5]), .ZF(LED[6]), .OVF(LED[7]));
//    AddSub4 lab(SW[3:0], SW[7:4], SW[8], LED[3:0], LED[4], LED[5]);
endmodule
