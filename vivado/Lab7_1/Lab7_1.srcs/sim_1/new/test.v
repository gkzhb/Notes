`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 12/07/2018 09:36:01 AM
// Design Name: 
// Module Name: test
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


module test();

    reg clk, clr;
    wire [5:0] LED;
    always
    begin
        #5 clk = ~clk;
    end
    my a(.clk(clk), .reset(clr), .z(LED));
    initial
    begin
        clr = 1'b1;
        clk = 1'b0;
        #5 clr = 1'b0;
    end
endmodule
