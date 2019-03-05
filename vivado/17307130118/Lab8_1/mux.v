`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 12/12/2018 11:25:49 PM
// Design Name: 
// Module Name: mux2t1
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


module mux2t1(
    input [3:0] a, b,
    input sel,
    output [3:0] y
    );
    wire tmp;
    assign tmp = {4{sel}};
    assign y = (a & ~tmp) | (b & tmp);
endmodule

module mux4t1(
    input [15:0] in,
    input [1:0] sel,
    output [3:0] y
    );
    wire [3:0] d;
    assign d[0] = ~|sel;
    assign d[1] = sel[0] & ~sel[1];
    assign d[2] = ~sel[0] & sel[1];
    assign d[3] = &sel;
    assign y = (in[3:0] & {4{d[0]}}) | (in[7:4] & {4{d[1]}}) | (in[11:8] & {4{d[2]}}) | (in[15:12] & {4{d[3]}});
endmodule