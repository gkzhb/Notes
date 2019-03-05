`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 12/07/2018 08:25:18 AM
// Design Name: 
// Module Name: seq_rec_v
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


module seq_rec_v(
    input clk,
    input reset,
    output [5:0] z
    );
    reg [5:0] state, next_state;
    reg clk1, clk2;
    reg [2:0] t0, t1;
    parameter A = 6'b100_001, B = 6'b010_001, C = 6'b001_100, D = 6'b001_010;
    assign z = state;
    always @(posedge clk1 or posedge clk2 or posedge reset)
    begin
        if (reset)
            state <= A;
        else
            if (clk1)
                state <= next_state;
            else
                state <= next_state;
    end

    always @(state or clk1 or clk2)
    begin
        case (state)
            A: next_state <= clk2 ? B : A;
            B: next_state <= clk1 ? C : B;
            C: next_state <= clk2 ? D : C;
            D: next_state <= clk1 ? A : D;
        endcase
    end

    always @(posedge t0[2] or posedge clk)
    begin
    if (clk)
        if (clk1)
            clk1 <= 1'b0;
        else
            clk1 <= 1'b1;
    else
        if (clk1)
            clk1 <= 1'b0;
        else
            clk1 <= 1'b1;
    end
    always @(posedge t1[2] or posedge clk)
    begin
    if (clk)
        if (clk2)
            clk2 <= 1'b0;
        else
            clk2 <= 1'b1;
    else
        if (clk2)
            clk2 <= 1'b0;
        else
            clk2 <= 1'b1;        
    end
        
    
    always @(posedge clk or posedge reset)
    begin
        if (reset)
        begin
            t0 = 3'b000;
            t1 = 3'b110;
        end
        else
        begin
            t0 <= t0 + 1;
            t1 <= t1 + 1;
        end
    end
endmodule