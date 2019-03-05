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
    input [15:0] SW,
    input BTNC, BTNU, BTND,
    input CLK100MHZ,
    output [15:0] LED
    );
    wire clk1_4hz;
    wire [3:0] y2o, q1, q2, q3, q4, q5, yout, qaout;
    wire [2:0] sel6, csel6;
    wire ctrl;
    wire en1, en2, en3, en4, wen, sel7;
    wire cen2, cen3, cen4, cwen;
    assign sel7 = 1'b0;
    assign ctrl = SW[6];
    assign LED[15:0] = {q4, q1, q3, q2};
    assign en1 = BTNC;
    assign en4 = cen4;
    assign wen = cwen;
    assign {sel6, en2, en3} = {csel6, cen2, cen3} | ({SW[15:13], BTNU, BTND} & {5{ctrl}});
    clkdiv U0(.mclk(CLK100MHZ), .clk1_4hz(clk1_4hz));
    Reg U1(.d(y2o), .en(en1), .clk(clk1_4hz), .q(q1)),
        U2(.d(yout), .en(en2), .clk(clk1_4hz), .q(q2)),
        U3(.d(yout), .en(en3), .clk(clk1_4hz), .q(q3)),
        U9(.d(qaout), .en(en4), .clk(clk1_4hz), .q(q5));
   mux2t1 U5(.a(SW[11:8]), .b(yout), .sel(SW[12]), .y(y2o)),
          U7(.a(q2), .b(q3), .sel(sel7), .y(q6));
   mux5t1 U6(.in({q5, q4, q3, q2, q1}), .sel(sel6), .y(yout));
   Ram U4(.din(yout), .wen(wen), .addr(SW[3:0]), .clk(clk1_4hz), .qout(q4));
   AddSub4 U8(.A(yout), .B(q6), .SIGN(sel7), .S(qaout));
//   Adder U8(.in1(yout), .in2(q6), .out(qaout));
   Control U10(.in(SW[5:4]), .clk(clk1_4hz), .clr(ctrl), .sel(csel6), .en({cen2, cen3, cen4, cwen}));
endmodule