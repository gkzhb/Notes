`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/07/2018 06:49:35 PM
// Design Name: 
// Module Name: Hex7Seg
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


module Hex7Seg(
    input [3:0] data,
    output reg [6:0] a2g
    );
    // A2G: g,f,e,d,c,b,a
    always @(data)
    case (data)
        'h0: a2g = 7'b100_0000;
        'h1: a2g = 7'b111_1001;
        'h2: a2g = 7'b010_0100;
        'h3: a2g = 7'b011_0000;
        'h4: a2g = 7'b001_1001;
        'h5: a2g = 7'b001_0010;
        'h6: a2g = 7'b000_0010;
        'h7: a2g = 7'b111_1000;
        'h8: a2g = 7'b000_0000;
        'h9: a2g = 7'b001_0000;
        'hA: a2g = 7'b000_1000;
        'hB: a2g = 7'b000_0011;
        'hC: a2g = 7'b100_0110;
        'hD: a2g = 7'b010_0001;
        'hE: a2g = 7'b000_0110;
        'hF: a2g = 7'b000_1110;
    default: a2g = 7'b100_0000;
    endcase                           
endmodule
