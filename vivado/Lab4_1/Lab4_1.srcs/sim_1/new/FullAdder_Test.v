`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/12/2018 10:53:56 PM
// Design Name: 
// Module Name: FullAdder_Test
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


module FullAdder_Test();

    reg [2:0] in;
    wire S, Co;
    FullAdder test(.A(in[2]), .B(in[1]), .Cin(in[0]), .S(S), .Co(Co));
    
    initial
    begin
        for(in = 0; in < 7; )
            #10 in = in + 1;
    end

endmodule
