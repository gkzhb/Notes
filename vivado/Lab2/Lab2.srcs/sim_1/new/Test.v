`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/01/2018 08:37:17 PM
// Design Name: 
// Module Name: Test
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


module Test(

    );

    wire [2:0] cin;
    wire [1:0] cG2;
    wire cG1;
    
    wire [7:0] out;
    reg [2:0] in;
    reg [1:0] G2;
    reg G1;
    decode3to8 a(out, cin, cG1, cG2);
    

    
    assign cin = in;
    assign cG2 = G2;
    assign cG1 = G1; 
    
    initial
    begin
        //for (G1 = 1'b0; G1 < 1; G1 = 1'b1)
        //begin
            G1 = 1'b1;
            #10 G2 = 2'b0;
            for (; G2 < 3; G2 = G2 + 1)
            begin
                #10 in = 3'b0;
                for (; in < 7;)
                    #10 in = in + 1;
                #10 in = 3'b0;
                for (; in < 7;)
                    #10 in = in + 1;
            end
        //end
    end
    initial #2000 $finish;
    
endmodule
