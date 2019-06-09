`timescale 1ns / 1ps

module set(
	input CLK,
	input Reset,
	input [6:0] Ctls,
	input [31:0] Addr, WD, MemReadData,
	output Hit, Dirty,
	output [31:0] ReadData,
	output [25:0] OutTag);
// Cache 中的组模块 一组中包含4路，即4个块，并且使用LRU替换算法

	wire wen, setValid, setDirty, init, offsetSW;
	wire [1:0] offset, s;
	wire [3:0] valid, dirty, we, eq;
	wire [25:0] tag[3:0], setTag, inTag;
	wire [31:0] rd[3:0];
	wire [31:0] wd;

	assign inTag = Addr[31:6];
	assign {wen, setValid, setDirty, offset, init, offsetSW} = Ctls;
	assign eq[0] = ~|(inTag + (~tag[0] + 1)) & valid[0];
	assign eq[1] = ~|(inTag + (~tag[1] + 1)) & valid[1];
	assign eq[2] = ~|(inTag + (~tag[2] + 1)) & valid[2];
	assign eq[3] = ~|(inTag + (~tag[3] + 1)) & valid[3];

	// flopenr #(26) tags(CLK, Reset, init, inTag, setTag);
	assign setTag = inTag;

	block blk0(CLK, Reset, offset, we[0], setValid, setDirty, setTag, wd, valid[0], dirty[0], tag[0], rd[0]);
	block blk1(CLK, Reset, offset, we[1], setValid, setDirty, setTag, wd, valid[1], dirty[1], tag[1], rd[1]);
	block blk2(CLK, Reset, offset, we[2], setValid, setDirty, setTag, wd, valid[2], dirty[2], tag[2], rd[2]);
	block blk3(CLK, Reset, offset, we[3], setValid, setDirty, setTag, wd, valid[3], dirty[3], tag[3], rd[3]);

	// LRU替换算法控制
	replacecontroller replctl(CLK, Reset, init, valid, eq, s, Hit);


	decode2to4 #(1) repdec(wen, s, we[0], we[1], we[2], we[3]);
	mux4 #(59) outmux({dirty[0], rd[0], tag[0]}, {dirty[1], rd[1], tag[1]}, {dirty[2], rd[2], tag[2]}, {dirty[3], rd[3], tag[3]}, s, {Dirty, ReadData, OutTag});
	mux2 #(32) wdmux(MemReadData, WD, offsetSW, wd);

endmodule
