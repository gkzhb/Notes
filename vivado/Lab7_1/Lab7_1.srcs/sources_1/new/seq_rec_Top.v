`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 12/07/2018 08:53:00 AM
// Design Name: 
// Module Name: seq_rec_Top
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


module seq_rec_Top(
    input CLK100MHZ,
    input [0:0] SW,
    output [5:0] LED
    );
    wire [2:0] clk;
    my a(.clk(clk[2]), .reset(SW[0]), .z(LED));
    clkdiv b(CLK100MHZ, SW[0], clk[0], clk[1], clk[2]);
endmodule
