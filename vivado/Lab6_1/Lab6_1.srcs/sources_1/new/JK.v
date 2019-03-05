`timescale 1ns / 1ps

module JK(
    input clk,
    input J, K,
    output reg Q,
    output nQ);
    
    assign nQ = ~Q;
    always @(posedge clk)
        case ({J, K})
            2'b00: Q <= Q;
            2'b01: Q <= 1'b0;
            2'b10: Q <= 1'b1;
            2'b11: Q <= ~Q;
        endcase
endmodule
