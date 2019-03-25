`timescale 1ns / 1ps

module cputest();

    reg CLK100MHZ;
    reg [7:0] SW;
    wire CG, CF, CE, CD, CC, CB, CA;
    wire [7:0] AN;
    wire DP;
	wire [15:0] LED;
	wire [31:0] out, addr, PC;
	wire mw;
	wire [4:0] ReadReg;
	wire [5:0] ReadMem;
	wire [31:0] RegData, MemData;
	wire clk;

	assign LED = PC[19:4];
	assign clk = CLK100MHZ;
	
	top topmips(clk, SW[7], out, addr, mw, ReadReg, ReadMem, RegData, MemData, PC);
	display displaydata(SW[0], SW[6:1], RegData, MemData, clk, SW[7], ReadReg, ReadMem, {CG, CF, CE, CD, CC, CB, CA}, AN, DP);
	clkdiv clocker(CLK100MHZ, SW[7], clk190hz, clk48hz, clk1hz);

	always
    begin
        CLK100MHZ <= 1; #5; CLK100MHZ <= 0; #5;
    end

	initial begin
	SW[7] <= 1'b1; 
	SW[6:1] <= 6'b000_010;
	SW[0] <= 1'b0;
	#10;
	SW[7] <= 1'b0;
	end

endmodule

