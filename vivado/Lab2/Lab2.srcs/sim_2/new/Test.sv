`timescale 1ns / 1ps

module Test();


    logic [3:0] out;
    logic [2:0] in;
    logic swt;
    decode2to4 a(out, in, swt);
    
    initial
    begin
            swt = 1'b0; in = 3'b00;
            for (in = 3'b0; in < 7;)
                #10 in = in + 1;  
       #10  swt = 1'b1; in = 3'b00;
            for (in = 3'b0; in < 7;)
                #10 in = in + 1;
    end
    //initial #100 $finish

endmodule