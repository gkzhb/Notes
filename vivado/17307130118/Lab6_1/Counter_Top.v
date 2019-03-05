`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/29/2018 03:57:39 PM
// Design Name: 
// Module Name: Counter_Top
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


module Counter_Top(
    input [8:0] SW,
    input BTNC,
    input CLK100MHZ,
    output [4:0] LED
    );
    wire clk190, clk1, clk48;
    clkdiv setclock(CLK100MHZ, SW[8], clk190, clk48, clk1);
    Counter test(.in(SW[3:0]), .clk(clk1), .clr(SW[7]),
        .load(SW[4]), .enP(SW[5]), .enT(SW[6]), .Q(LED[3:0]),.cout(LED[4]));
endmodule
