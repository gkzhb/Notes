`timescale 1ns / 1ps

module simcpu();

	reg CLK, Reset;
	wire [31:0] PC, PCNext, DispRegData, DispMemData, Instr;
	
	mips_top mipstopwithcache(CLK, Reset, PC, PCNext, 5'b0, 7'b0, DispRegData, DispMemData, Instr);

	initial
	begin
		Reset <= 1; #10; Reset <= 0;
	end

	always
	begin
		CLK <= 1; #5; CLK <= 0; #5;
	end

endmodule
