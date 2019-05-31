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
