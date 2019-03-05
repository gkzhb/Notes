`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/07/2018 07:05:39 PM
// Design Name: 
// Module Name: async7seg
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


module async7seg(
    input [15:0] x,
    input clk,
    input clr,
    output [6:0] a2g,
    output reg [3:0] an,
    output dp
    );
    
    wire [1:0] s;
    reg [3:0] digit;
    wire [3:0] aen;
    reg [19:0] clkdiv;
    
    assign dp = 1; // 关闭小数点
    assign s = clkdiv[19:18];
    assign aen = 4'b1111;
    
    always @(s)
    case (s)
        0:digit = x[3:0];
        1:digit = x[7:4];
        2:digit = x[11:8];
        3:digit = x[15:12];
        default:digit = x[3:0];
    endcase
    
    always @(aen)
    begin
        an = 4'b1111;
        if(aen[s] == 1)
            an[s] = 0;
    end
    
    always @(posedge clk or posedge clr)
    begin
        if(clr == 1)
            clkdiv <= 0;
        else
            clkdiv <= clkdiv + 1;
    end
    
    Hex7Seg seg1(.data(digit), .a2g(a2g));
endmodule
