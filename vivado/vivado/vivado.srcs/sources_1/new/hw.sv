`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/07/2018 04:01:07 PM
// Design Name: 
// Module Name: hw
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


module hw(
    input logic [3:0] a,
    output logic [5:0] z);
    
    assign z[5] = &a;
    assign z[4] = ~&a;
    assign z[3] = |a;
    assign z[2] = ~|a;
    assign z[1] = ^a;
    assign z[0] = ~^a;
            
    
endmodule
