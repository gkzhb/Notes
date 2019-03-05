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

module mux5t1(
    input [19:0] in,
    input [2:0] sel,
    output reg [3:0] y
    );
    always @(sel, in)
    begin
        case (sel)
        3'b000: y <= in[3:0];
        3'b001: y <= in[7:4];
        3'b010: y <= in[11:8];
        3'b011: y <= in[15:12];
        3'b100: y <= in[19:16];
        endcase
    end
        
endmodule