`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 12/07/2018 10:58:53 AM
// Design Name: 
// Module Name: counter
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


module counter(
    input clk,
    input st,
    output ts,
    output tl
    );
    
    reg [3:0] tm;
    always @(posedge clk or posedge st)
    begin
        if (st)
            tm <= 4'b1111;
        else
            tm <= tm + 1;
    end
    assign ts = ~tm[3]&&tm[2]&&~tm[1]&&~tm[0];
    assign tl = ~(|tm);
    
endmodule
