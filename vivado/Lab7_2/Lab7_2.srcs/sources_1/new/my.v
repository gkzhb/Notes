`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 12/07/2018 10:57:01 AM
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
    input c,
    output reg [5:0] z
    );
    
    wire tl, ts;
    reg st;
    counter aa(clk, st, ts, tl);
    parameter A = 6'b100_001, B = 6'b010_001, C = 6'b001_100, D = 6'b001_010;
        
    always @(posedge clk)
    begin
        if (c)
        begin
            case (z)
                 A: z = tl ? B : A;
                 B: z = ts ? C : B;
                 C: z = tl ? D : C;
                 D: z = ts ? A : D;
            endcase
        end
        else
            z <= A;
    end
    always @(posedge clk)
    begin
        if (c)
            st <= 1'b0;
        else
            st <= 1'b1;
    end
endmodule

module DTri(
    input clk,
    input D,
    output reg Q,
    output nQ);
    
    assign nQ = ~Q;
    always @(posedge clk)
        Q <= D;
endmodule
