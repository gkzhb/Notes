`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/12/2018 06:09:16 PM
// Design Name: 
// Module Name: FullAdder_Top
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


module FullAdder_Top(
    input [2:0] SW,
    output [1:0] LED
    );
    
    FullAdder a(.A(SW[2]), .B(SW[1]), .Cin(SW[0]), .S(LED[0]), .Co(LED[1]));
    
endmodule
