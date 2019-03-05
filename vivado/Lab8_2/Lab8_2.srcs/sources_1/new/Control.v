`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 12/14/2018 10:24:30 AM
// Design Name: 
// Module Name: Control
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

module Control(
    input [1:0] in,
    input clk,
    input clr,
    output reg [2:0] sel,
    output reg [3:0] en
    );
    reg [6:0] stat, nstat;
    parameter s0 = 7'b0000000,
    s1 = 7'b0010001,
    s2 = 7'b0101000,
    s3 = 7'b0110100,
    s4 = 7'b1000000,
    s5 = 7'b0100010,
    s6 = 7'b1001000;
//    assign {sel[2:0], en[3:0]} = stat;
    always @(posedge clk, posedge clr)
        if (clr)
            stat <= s0;
        else
            stat <= nstat;
    always @(*)
    begin
        if (in == 2'b01)
            case (stat)
                s0: nstat <= s1;
                s1: nstat <= s2;
                s2: nstat <= s3;
                s3: nstat <= s4;
                s4: nstat <= s4;
                default: nstat <= s0;
            endcase
        else
            if (in == 2'b10)
                case (stat)
                    s0: nstat <= s5;
                    s5: nstat <= s6;
                    s6: nstat <= s4;
                    s4: nstat <= s4;
                    default: nstat <= s0;
                endcase
            else
                nstat <= s0;
    end
    always @(*)
        {sel[2:0], en[3:0]} = stat;
endmodule
