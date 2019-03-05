`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 12/12/2018 11:45:39 PM
// Design Name: 
// Module Name: Ram
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


module Ram(
    input [3:0] din,
    input wen,
    input clk,
    input [3:0] addr,
    output [3:0] qout
    );
    reg [3:0] mem[2**4-1:0];
    always @(posedge clk)
        if (wen)
            mem[addr] <= din;
    assign qout = mem[addr];
endmodule
