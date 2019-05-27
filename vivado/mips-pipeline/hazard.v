`timescale 1ns / 1ps

module hazard(
	input [4:0] rsD, rtD, rsE, rtE,
	input [4:0] WriteRegE, WriteRegM, WriteRegW,
	input RegWriteE, RegWriteM, RegWriteW,
	input MemToRegE, MemToRegM, BranchD,
	output ForwardaD, ForwardbD,
	output reg [1:0] ForwardaE, ForwardbE,
	output StallF, StallD, FlushE);

	wire lwstallD, branchstallD;

	assign ForwardaD = (rsD != 5'b0 & rsD == WriteRegM & RegWriteM);
	assign ForwardbD = (rtD != 5'b0 & rtD == WriteRegM & RegWriteM);
	
	always @(*)
	begin
		ForwardaE = 2'b00;
		ForwardbE = 2'b00;
		if (rsE != 0)
			if (rsE == WriteRegM & RegWriteM)
				ForwardaE = 2'b10;
			else
				if (rsE == WriteRegW & RegWriteW)
					ForwardaE = 2'b01;
		if (rtE != 0)
			if (rtE == WriteRegM & RegWriteM)
				ForwardbE = 2'b10;
			else
				if (rtE == WriteRegW & RegWriteW)
					ForwardbE = 2'b01;
	end

	assign lwstallD = MemToRegE & (rtE == rsD | rtE == rtD);
	assign branchstallD = BranchD &
			(RegWriteE & (WriteRegE == rsD | WriteRegE == rtD) |
			MemToRegM & (WriteRegM == rsD | WriteRegM == rtD));

	assign StallD = lwstallD | branchstallD;
	assign StallF = StallD;
	assign FlushE = StallD;

endmodule
