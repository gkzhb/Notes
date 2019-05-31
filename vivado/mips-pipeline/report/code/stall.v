	assign lwstallD = MemToRegE & (rtE == rsD | rtE == rtD);
	assign branchstallD = BranchD &
			(RegWriteE & (WriteRegE == rsD | WriteRegE == rtD) |
			MemToRegM & (WriteRegM == rsD | WriteRegM == rtD));

	assign StallD = lwstallD | branchstallD;
	assign StallF = StallD;
	assign FlushE = StallD;
