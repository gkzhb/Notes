`timescale 1ns / 1ps

module dec();
    reg [5:0] op;
    wire mtr, mw,b, as, rd, rw, j, bne, eo;
    wire [1:0] ao;
    maindec md(op, mtr, mw, b, as, rd, rw, j, ao, bne, eo);
    initial
    begin
        op <= 6'b000000;
        #10; op <= 6'b001000;
        #10; op <= 6'b001100;
        #10; op <= 6'b101011;
    end
endmodule