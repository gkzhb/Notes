`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/29/2018 03:58:33 PM
// Design Name: 
// Module Name: Counter
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


module Counter(
    input [3:0] in,
    input clk,
    input clr,
    input load,
    input enP,
    input enT,
    output reg [3:0] Q,
    output cout
    );
    
    wire [3:0] nK;
    wire [3:0] nJ;
    wire [3:0] nQ;
    wire cl, len;
    assign cout = & Q;
    always @(posedge clk)
    begin
        if (clr == 1'b0)
            Q <= 4'b0000;
        else
            if (load == 1'b0)
                Q <= in;
            else
                if (enP == 1'b1 && enT == 1'b1)
                    Q <= Q + 1;
                else
                    Q <= Q;
    end
    
/*    assign cl = ~(clr & load);
    assign len = ~(cl | (~enP) | (~enT));
    assign cout = ~((| nQ) | (~ enT));

	assign nK[0] = ~((QA & len) | (cl & nJ[0]));
	assign nJ[0] = ~((A & clr & cl) | (len & nQ[0]));
	assign nK[1] = ~((QB & QA & len) | (cl & nJ[1]));
	assign nJ[1] = ~((B & clr & cl) | (len & QA & nQ[1]));
	assign nK[2] = ~((QC & QB & QA & len) | (cl & nJ[2]));
	assign nJ[2] = ~((C & clr & cl) | (len & QA & nQ[2]));
	assign nK[3] = ~((QD & QC & QB & QA & len) | (cl & nJ[3]));
	assign nJ[3] = ~((D & clr & cl) | (len & QA & nQ[3]));

	JK a(clk, nJ[0], nK[0], QA, nQ[0]),
		b(clk, nJ[1], nK[1], QB, nQ[1]),
		c(clk, nJ[2], nK[2], QC, nQ[2]),
		d(clk, nJ[3], nK[3], QD, nQ[3]);*/
    
endmodule
