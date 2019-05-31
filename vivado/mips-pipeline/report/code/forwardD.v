	assign ForwardaD = (rsD != 5'b0 & rsD == WriteRegM & RegWriteM);
	assign ForwardbD = (rtD != 5'b0 & rtD == WriteRegM & RegWriteM);
