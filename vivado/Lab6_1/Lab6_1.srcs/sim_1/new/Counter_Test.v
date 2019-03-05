`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/30/2018 07:57:49 AM
// Design Name: 
// Module Name: Counter_Test
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


module Counter_Test();

    wire [4:0] LED;
    wire clk1;
    reg clr2;
    reg clk2, en, clr, zero, load;
    Counter test({4{zero}}, clk1, clr,
        load, en, en, LED[3:0], LED[4]);
    always
    begin
       while(1)
        if (clk2 === 1'bX)
           clk2 = 1'b0;
        else
           #1 clk2 = ~clk2;
    end

    wire clk190, clk48;
    clkdiv setclock(clk2, clr2, clk1, clk190, clk48);

    initial
    begin
       zero = 1'b0;
       load = 1'b1;
       clr = 1'b1;
       en = 1'b0;
       clr2 = 1'b0;
       #10 clr = 1'b0;
       clr2 = 1'b1;
       #200 clr = 1'b1;

       load = 1'b0;
       #10 load = 1'b1;
       en = 1'b1;
    end

    


endmodule
