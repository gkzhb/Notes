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
    input [31:0] x,
    input clk,
    input clr,
    output [6:0] a2g,
    output reg [7:0] an,
    output dp
    );
// 七段数码管显示 32 位数据
    wire [2:0] s;
    reg [3:0] digit;
    wire [7:0] aen;
    reg [2:0] clkdiv;
    
    assign dp = 1; // 关闭小数点
    assign s = clkdiv;
    assign aen = 8'b1111_1111;
    
    always @(s)
    case (s)
        0:digit = x[3:0];
        1:digit = x[7:4];
        2:digit = x[11:8];
        3:digit = x[15:12];
        4:digit = x[19:16];
        5:digit = x[23:20];
        6:digit = x[27:24];
        7:digit = x[31:28];
        default:digit = x[3:0];
    endcase
    
    always @(aen, s)
    begin
        an = 8'b1111_1111;
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
