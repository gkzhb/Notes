`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/02/2018 08:54:03 AM
// Design Name: 
// Module Name: decode_Top
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


module decode_Top(
    input [7:0]SW,
    output [3:0]LED
    );
    
    encode(.Y(LED[2:0]),.V(LED[3]), .S(SW[7:0]));
endmodule
