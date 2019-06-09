`timescale 1ns / 1ps

module cache(
	input CLK, Reset, En, Suspense,
	input [31:0] Addr,
	input WE,
	input [31:0] WD,
	output Hit,
	output [31:0] RD,

	output [31:0] MAddr,
	output MWE,
	output [31:0] MWD,
	input MReady,
	input [31:0] MRD);
// Cache 缓存模块 缓存为64字4路4组组相联高速缓存


	wire [6:0] ctls, ctls0, ctls1, ctls2, ctls3;
	wire [1:0] blockOffset, offset;
	wire hit0, hit1, hit2, hit3;
	wire [25:0] outTag0, outTag1, outTag2, outTag3, outTag, tag;
	wire dirty, dirty0, dirty1, dirty2, dirty3;
	wire [31:0] rd0, rd1, rd2, rd3, rd;
	wire cwe, we, setValid, setDirty, init, offsetSW;
	wire [31:0] addr, wd;

	assign addr = Addr;
	assign wd = WD;
	assign cwe = WE;
	// flopenr #(32) address(~CLK, Reset, init, Addr, addr);
	// flopenr #(32) writedata(~CLK, Reset, init, WD, wd);
	// flopenr #(1) writeenable(~CLK, Reset, init, WE, cwe); // Cache WriteEnable

	assign ctls = {we, setValid, setDirty, offset, init, offsetSW};

	cachecontroller cctls(CLK, Reset, En, Suspense, cwe, Hit, MReady, dirty, we, setValid, setDirty, MWE, blockOffset, init, offsetSW);

	decode2to4 #(7) cdecode(ctls, addr[5:4], ctls0, ctls1, ctls2, ctls3);
	mux4 #(60) dtmux({hit0, rd0, dirty0, outTag0}, {hit1, rd1, dirty1, outTag1}, {hit2, rd2, dirty2, outTag2}, {hit3, rd3, dirty3, outTag3}, addr[5:4], {Hit, rd, dirty, outTag});
	mux2 #(32) rdmux(32'b0, rd, Hit & ~cwe & En, RD);
	mux2 #(58) mwmux({32'b0, addr[31:6]}, {rd, outTag}, MWE, {MWD, tag});
	assign MAddr = {tag, addr[5:4], offset, 2'b00};

	set set0(CLK, Reset, ctls0, addr, wd, MRD, hit0, dirty0, rd0, outTag0);
	set set1(CLK, Reset, ctls1, addr, wd, MRD, hit1, dirty1, rd1, outTag1);
	set set2(CLK, Reset, ctls2, addr, wd, MRD, hit2, dirty2, rd2, outTag2);
	set set3(CLK, Reset, ctls3, addr, wd, MRD, hit3, dirty3, rd3, outTag3);

	mux2 #(2) offsetmux(blockOffset, addr[3:2], offsetSW, offset);

endmodule
