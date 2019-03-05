`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/07/2018 04:17:17 PM
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
    
    logic [3:0] a;
    logic [5:0] z;
//    logic [3:0] i;
    hw G(a, z);
    
    initial
        begin
/*            a[0] = 1; a[1] = 1; a[2] = 1; a[3] = 1;       
            for(i[0] = 0; i[0] < 1; i[0] = 1)
            begin
                #10 a[0] = i[0];
                for(i[1] = 0; i[1] < 1; i[1] = 1)
                    begin
                    #10 a[1] = i[1];
                    for(i[2] = 0; i[2] < 1; i[2] = 1)
                            begin
                            #10 a[2] = i[2];
                        for(i[3] = 0; i[3] < 1; i[3] = 1)
                                        #10 a[3] = i[3];                             
                            end                    
                    end
            end*/
            
            for (a = 0; a < 16; )
                  #10 a = a + 1;       
        end
        
endmodule
