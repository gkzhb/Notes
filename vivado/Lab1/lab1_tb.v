`timescale 1ns / 1ps
/////////////////////////////////////////////////////////////////
// Module Name: lab1_tb
/////////////////////////////////////////////////////////////////
module lab1_tb();
    
    reg [7:0] switches;
    wire [7:0] leds;
    
    lab1 dut(.led(leds),.swt(switches));
    initial
    begin
   switches=8'b00000000;
   #50 switches=8'b00000001;
   #50 switches=8'b00000010;
   #50 switches=8'b00000011;
   #50 switches=8'b00000100;
   #50 switches=8'b00000101;
   #50 switches=8'b00000110;
   #50 switches=8'b00000111;
   #50 switches=8'b00001000;
   #50 switches=8'b00001001;
   #50 switches=8'b00001010;
   #50 switches=8'b00001011;
   #50 switches=8'b00001100;
   #50 switches=8'b00001101;
   #50 switches=8'b00001110;
   #50 switches=8'b00001111;
   #50 switches=8'b00010000;
   #50 switches=8'b00010001;
   #50 switches=8'b00010010;
   #50 switches=8'b00010011;
   #50 switches=8'b00010100;
   #50 switches=8'b00010101;
   #50 switches=8'b00010110;
   #50 switches=8'b00010111;  
    end
      
endmodule
