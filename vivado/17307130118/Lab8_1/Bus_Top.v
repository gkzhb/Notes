`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 12/12/2018 11:06:56 PM
// Design Name: 
// Module Name: Bus_Top
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


module Bus_Top(
    input [14:0] SW,
    input CLK100MHZ,
    output [15:0] LED
    );
    wire clk1_4hz;
    wire [3:0] y2o, q1, q2, q3, q4, yout;
    assign LED[15:0] = {q4, q1, q3, q2};
    clkdiv U0(.mclk(CLK100MHZ), .clk1_4hz(clk1_4hz));
    Reg U1(.d(y2o), .en(SW[7]), .clk(clk1_4hz), .q(q1)),
        U2(.d(yout), .en(SW[6]), .clk(clk1_4hz), .q(q2)),
        U3(.d(yout), .en(SW[5]), .clk(clk1_4hz), .q(q3));
   mux2t1 U5(.a(SW[11:8]), .b(yout), .sel(SW[12]), .y(y2o));
   mux4t1 U6(.in({q4, q3, q2, q1}), .sel(SW[14:13]), .y(yout));
   Ram U4(.din(yout), .wen(SW[0]), .addr(SW[4:1]), .clk(clk1_4hz), .qout(q4));
endmodule
