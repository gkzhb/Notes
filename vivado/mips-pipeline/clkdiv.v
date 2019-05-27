`timescale 1ns / 1ps

module clkdiv(
    input mclk,
    input clr,
    output clk1,
    output clk2,
    output clk3
    );
// 时钟降频
    reg [27:0]q;
    always@(posedge mclk)
    begin
    if(clr)
         q<=0;
    else
         q<=q+1;
    end
    assign clk1=q[2];
    assign clk2=q[16];
    assign clk3=q[25];
endmodule
