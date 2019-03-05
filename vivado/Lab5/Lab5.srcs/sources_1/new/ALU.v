`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/22/2018 11:20:26 PM
// Design Name: 
// Module Name: ALU
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


module ALU(
    input [2:0] S,
    input [3:0] A,
    input [3:0] B,
    input Cn,
    input M,
    output reg [3:0] F,
    output reg Cn4,
    output reg NF,
    output reg ZF,
    output reg OVF
    );
    
    wire [4:0] res1;
    wire [4:0] res2;
    wire [1:0] ovf;
    AddSub4 a(.A(A[3:0]), .B(B[3:0]), .SIGN(S[0]), .S(res1[3:0]), .CF(res1[4]), .OVF(ovf[0])),
        b(.A(res1[3:0]), .B({3'b000, Cn}), .SIGN(S[0]), .S(res2[3:0]), .CF(res2[4]), .OVF(ovf[1]));
    
    
    always @(*)
    begin
        if (M == 1'b1)
        begin
            Cn4 = res1[4] | res2[4];
            F = res2[3:0];
            OVF = | ovf;
        end
        else
        begin
            case(S)
                2'b00: F = ~A;
                2'b01: F = A & B;
                2'b10: F = A | B;
                2'b11: F = A ^ B;
                default: F = A;
            endcase
            OVF = 1'b0;
            Cn4 = 1'b0;
        end
    NF = F[3];
    ZF = ~(|F);
    end
endmodule
