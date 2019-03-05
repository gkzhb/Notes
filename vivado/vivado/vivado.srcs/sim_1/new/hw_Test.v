`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/07/2018 04:11:53 PM
// Design Name: 
// Module Name: hw_Test
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


module hw_Test(

    );
    
    logic a, b;
    logic [5:0] z;
    
    hw G(a, b, z);
    
    initial
        begin
                a = 0; b = 0;
            #10 a = 0; b = 1;
            #10 a = 1; b = 0;
            #10 a = 1; b = 1;
        end
        
endmodule
