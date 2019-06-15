	block blk0(CLK, Reset, offset, we[0], setValid, setDirty, setTag, wd,
				valid[0], dirty[0], tag[0], rd[0]);
	block blk1(CLK, Reset, offset, we[1], setValid, setDirty, setTag, wd,
				valid[1], dirty[1], tag[1], rd[1]);
	block blk2(CLK, Reset, offset, we[2], setValid, setDirty, setTag, wd,
				valid[2], dirty[2], tag[2], rd[2]);
	block blk3(CLK, Reset, offset, we[3], setValid, setDirty, setTag, wd,
				valid[3], dirty[3], tag[3], rd[3]);

	// LRU替换算法控制
	replacecontroller replctl(CLK, Reset, init, valid, eq, s, Hit);

	// 写使能端信号译码器
	decode2to4 #(1) repdec(wen, s, we[0], we[1], we[2], we[3]);
	// 输出信号选择
	mux4 #(59) outmux({dirty[0], rd[0], tag[0]},
					{dirty[1], rd[1], tag[1]},
					{dirty[2], rd[2], tag[2]},
					{dirty[3], rd[3], tag[3]},
					s, {Dirty, ReadData, OutTag});
	// 写入块的数据选择
	mux2 #(32) wdmux(MemReadData, WD, offsetSW, wd);
