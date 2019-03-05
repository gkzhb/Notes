`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/13/2018 04:25:46 PM
// Design Name: 
// Module Name: Adder_Top
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


module Adder_Top(
    input [8:0] SW,
    output [4:0] LED
    );
    
    Adder(.in1(SW[3:0]), .in2(SW[7:4]), .Cin(SW[8]), .out(LED[3:0]), .Co(LED[4]));
    
endmodule
