`timescale 1ns / 1ps

module simcache();

	reg CLK, Reset;
	reg Suspense, WE, ready;
	reg [31:0] Addr, WD;
	wire Hit, MWE, MReady;
	wire [31:0] RD, MAddr, MWD, MRD, data;
	cache testcache(CLK, Reset, Suspense, Addr, WE, WD, Hit, RD,
					MAddr, MWE, MWD, MReady, MRD);
	dmem memory(CLK, Reset, MWE, MAddr, MWD, MReady, MRD, 7'b001_0000, data);

	initial
	begin
		Suspense <= 0;
		ready <= 0;
		WE <= 1;
		Addr <= 0;
		WD <= 32'h0000_000e;
		Reset <= 1; #5; Reset <= 0;
		ready <= 1;
	end

	always @(posedge CLK)
	begin
		if (ready)
		begin
			WD <= WD + {31'b0, Hit};
			Addr <= Addr + {29'b0, Hit, 2'b0};
		end
	end

	always
	begin
		CLK <= 1; #5; CLK <= 0; #5;
	end

endmodule
