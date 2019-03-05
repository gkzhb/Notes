`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/02/2018 12:42:11 AM
// Design Name: 
// Module Name: test1
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


module test1(


    );
    logic [3:0] out;
    logic [1:0] in;
    logic swt;
    decode a(out, in, swt);
    
    initial
    begin
            swt = 1'b0; in = 2'b00;
            for (in = 2'b0; in < 3;)
                #10 in = in + 1;  
       #10  swt = 1'b1; in = 2'b00;
            for (in = 2'b0; in < 3;)
                #10 in = in + 1;
    end
    //initial #100 $finish
endmodule
