	always @(*)
	begin
		if (Ctl[1] == 0)
		begin
			case(Ctl[0])
				1'b0:
				begin
					DispReadReg <= Addr[4:0];
					DispReadMem <= 6'b0;
					Data[15:0] <= DispRegData;
				end
				1'b1:
				begin
					DispReadReg <= 5'b0;
					DispReadMem <= Addr;
					Data[15:0] <= DispMemData[15:0];
				end
			endcase
			Data[31:16] <= {PC[7:0], PCNext[7:0]};
		end
		else
		begin
			Data <= Instr;
		end
	end
