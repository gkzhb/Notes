`timescale 1ns / 1ps

module simcache();

	reg CLK, Reset;
	reg En, Suspense, WE, ready;
	reg [31:0] Addr, WD;
	wire Hit, MWE, MReady;
	wire [31:0] RD, MAddr, MWD, MRD, data;
	cache testcache(CLK, Reset, En, Suspense, Addr, WE, WD, Hit, RD,
					MAddr, MWE, MWD, MReady, MRD);
	dmem memory(CLK, Reset, MWE, MAddr, MWD, MReady, MRD, 7'b001_0000, data);

	initial
	begin
		En <= 1;
		Suspense <= 1;
		ready <= 0;
		WE <= 1;
		Addr <= 0;
		WD <= 32'h0000_000e;
		Reset <= 1; #5; Reset <= 0;
		ready <= 1;
		#165;
		Suspense <= 0;
		ready <= 0;
		#10;
		WE <= 0;
	end

	always
	begin
		CLK <= 1; #5; CLK <= 0; #5;
	end

endmodule
