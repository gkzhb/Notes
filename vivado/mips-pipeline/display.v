`timescale 1ns / 1ps

module display(
	input CLK, Reset,
	input [1:0] Ctl,
	input [6:0] Addr,
	input [31:0] DispRegData, DispMemData,
	output reg [4:0] DispReadReg,
	output reg [6:0] DispReadMem,
	input [31:0] PC, PCNext, Instr,
	output [6:0] A2G,
	output [7:0] AN,
	output DP);

	reg [31:0] Data;

	async7seg seg(Data, CLK, Reset, A2G[6:0], AN[7:0], DP);

	always @(*)
	begin
		if (Ctl[1] == 0)
		begin
			case(Ctl[0])
				1'b0:
				begin
					DispReadReg <= Addr[4:0];
					DispReadMem <= 7'b0;
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

endmodule
