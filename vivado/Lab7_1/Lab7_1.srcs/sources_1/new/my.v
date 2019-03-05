`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 12/07/2018 09:48:34 AM
// Design Name: 
// Module Name: my
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


module my(
    input clk,
    input reset,
    output [5:0] z
    );
    reg [5:0] state, next_state;
    wire clk1, clk2;
    wire clock;
    reg [2:0] t0, t1;
    reg [3:0] tm;
    parameter A = 6'b100_001, B = 6'b010_001, C = 6'b001_100, D = 6'b001_010;
    assign clock = clk1 | clk2;
    assign z = state;
    
    always @(posedge clk, posedge reset)
    begin
        if (reset)
            tm <= 0;
        else
            tm <= tm + 1;
    end

    assign clk1 = ~tm[3]&&tm[2]&&tm[1]&&~tm[0];
    assign clk2 = ~(|tm);
    
    always @(posedge clock, posedge reset)
    begin
        if (reset)
            state <= A;
        else
            state <= next_state;
    end

    always @(state or clk1 or clk2)
    begin
        case (state)
            A: next_state = clk2 ? B : A;
            B: next_state = clk1 ? C : B;
            C: next_state = clk2 ? D : C;
            D: next_state = clk1 ? A : D;
        endcase
    end
endmodule
