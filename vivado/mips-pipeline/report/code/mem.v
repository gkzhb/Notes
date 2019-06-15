	assign nextstate = state + 1;

	always @(posedge CLK)
		if (Reset)
			state <= 2'b00;
		else
			state <= nextstate;

	always @(*)
		if (state == 2'b11)
		begin
			Ready <= 1'b1;
			RD <= RAM[A[7:2]];
		end
		else
		begin
			Ready <= 1'b0;
			RD <= 32'b0;
		end
