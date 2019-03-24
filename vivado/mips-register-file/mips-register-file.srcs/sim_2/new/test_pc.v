`timescale 1ns / 1ps

module test_pc();

    reg [31:0] next, a, b;
    reg [4:0] ra, rb, rw;
    reg we;
    reg reset;
    reg clk;
    wire [31:0] out, outa, outb;
    flopr #(32) PC(clk, reset, next, out);
    regfile rf(clk, we, ra, rb, rw, next, outa, outb);
	always
    begin
        clk <= 1; #5; clk <= 0; #5;
    end
    
    initial
    begin
       reset <= 1;ra <= 5'b00000; rb <= 5'b00001; rw <= 5'b00010; we <= 0;
       next <= 32'b0; #22; reset <= 0;
       next <= 32'b0001; #10;
       we <= 1; next <= 32'b0010; #10;
       we <= 0; next <= 32'b0011; #10;
       ra <= 5'b00010;
    end
endmodule