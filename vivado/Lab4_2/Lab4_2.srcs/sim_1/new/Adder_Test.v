`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/13/2018 04:34:24 PM
// Design Name: 
// Module Name: Adder_Test
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


module Adder_Test();

    reg [8:0] in;
    wire [4:0] out;
    
    Adder test(.in1(in[3:0]), .in2(in[7:4]), .Cin(in[8]), .out(out[3:0]), .Co(out[4]));

    initial
    begin
        for(in = {1'b1, 8'b0}; in >= 0; )
            #10 in = in + 1;
    end

endmodule
