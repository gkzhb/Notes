`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/02/2018 09:43:47 AM
// Design Name: 
// Module Name: encode
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


module encode(
    output reg [2:0] Y,
    output V,
    input [7:0] S
    );
    
    assign V = |S;
    
    always @(S)
        case(S)
            8'b0000_0001:   Y = 3'b000;
            8'b0000_0010:   Y = 3'b001;
            8'b0000_0100:   Y = 3'b010;
            8'b0000_1000:   Y = 3'b011;
            8'b0001_0000:   Y = 3'b100;
            8'b0010_0000:   Y = 3'b101;
            8'b0100_0000:   Y = 3'b110;
            8'b1000_0000:   Y = 3'b111;
            default:        Y = 3'b000;
        endcase
            
endmodule

module encodePlus(
    output reg [2:0] Y,
    input [7:0] S
    );
    
    always @(S)
        casez(S)
            8'b0000_0001:   Y = 3'b000;
            8'b0000_001?:   Y = 3'b001;
            8'b0000_01??:   Y = 3'b010;
            8'b0000_1???:   Y = 3'b011;
            8'b0001_????:   Y = 3'b100;
            8'b001?_????:   Y = 3'b101;
            8'b01??_????:   Y = 3'b110;
            8'b1???_????:   Y = 3'b111;
        endcase
endmodule