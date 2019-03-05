`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/29/2018 11:07:30 PM
// Design Name: 
// Module Name: Clock
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


module Clock(
    input clk,
    input clr,
    input clr2,
	input load,
    output [6:0] a2g,
    output [3:0] an,
    output dp
    );

    wire [15:0] tm;
    wire [3:0] nclr;
	wire [3:0] cout;
    wire zero, en, nclk;
    wire nclr2;
    wire clk1hz, clk190hz, clk48hz;
    wire [3:0] clock;
    reg [3:0] clear;
    assign zero = 1'b0;
	assign en = 1'b1;
    assign nclr = ~clear;
    assign nclr2 = ~clr2;
    assign clock = {4{clk1hz}} & clear;
    assign nclk = ~clk1hz;

//    assign clear[0] = nclk & (tm[3:0] == 4'b1001) | ~clr;    // 变为 9 准备清零
//    assign clear[1] = nclk & (tm[7:4] == 4'b0101 & clear[0]) | ~clr; // 变为 59 准备清零
//    assign clear[2] = nclk & (tm[11:8] == 4'b1001 & clear[1]) | ~clr | clear[3]; // 分钟清零并且时钟个位为 9 清零，或者时钟清零时清零
//    assign clear[3] = nclk & (tm[15:12] == 4'b0010 & tm[11:8] == 4'b0011 & clear[1]) | ~clr; // 分钟清零并且时钟为 23 时清零

    always @(clk1hz)
    begin
        if (tm[3:0] == 4'b1001 | ~clr)
            begin
            clear[0] <= 1;
            if (tm[7:4] == 4'b0101 | ~clr)
                begin
                clear[1] <= 1;
                if (tm[11:8] == 4'b1001 | ~clr)
                    clear[2] <= 1;
                if (tm[15:12] == 4'b0010 & tm[11:8] == 4'b0011 | ~clr)
                begin
                    clear[3] <= 1;
                    clear[2] <= 1;
                end
                else
                    if (~(tm[11:8] == 4'b1001 | ~clr))
                        clear[2] <= 0;
                end
            else
                clear[1] <= 0;
            end
        else
            clear[0] <= 0;
    end

    clkdiv clocker(clk, clr2, clk190hz, clk48hz, clk1hz);
    Counter a({4{zero}}, clk1hz, nclr[0], load, en, en, tm[3:0], cout[0]),
	b({4{zero}}, clock[0], nclr[1], load, en, en, tm[7:4], cout[1]),
	c({4{zero}}, clock[1], nclr[2], load, en, en, tm[11:8], cout[2]),
	d({4{zero}}, clock[2], nclr[3], load, en, en, tm[15:12], cout[3]);   

	async7seg seg(tm[15:0], clk190hz, nclr2, a2g[6:0], an[3:0], dp);

endmodule
