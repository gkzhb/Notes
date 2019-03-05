`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/01/2018 08:28:38 PM
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
    output wire Y,
    input wire [1:0] I,
    input wire S);

    wire nS;
    wire a1, a2;
    not (nS, S);
    and (a1, I[0], nS),
        (a2, I[1], S);
    or  (Y, a1, a2);

endmodule
