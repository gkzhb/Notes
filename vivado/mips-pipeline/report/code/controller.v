	floprc #(8) regE(CLK, Reset, FlushE,
				{memToRegD, memWriteD, aluSrcD, regDstD, regWriteD, aluCtlD},
				{MemToRegE, memWriteE, ALUSrcE, RegDstE, RegWriteE, ALUCtlE});
	flopr #(3) regM(CLK, Reset,
				{MemToRegE, memWriteE, RegWriteE},
				{MemToRegM, MemWriteM, RegWriteM});
	flopr #(2) regW(CLK, Reset,
				{MemToRegM, RegWriteM},
				{MemToRegW, RegWriteW});
