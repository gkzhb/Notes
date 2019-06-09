`timescale 1ns / 1ps

module cachecontroller(
	input CLK, Reset, En, Suspense, CWE, Hit, MReady, Dirty,
	output WE, SetValid, SetDirty, MWE,
	output [1:0] BlockOffset,
	output Init,
	output reg OffsetSW,
	output [3:0] State);

	assign State = state;

	reg [3:0] state, nextstate;
	reg [5:0] ctls;
	wire we0, initstate;

	always @(posedge CLK)
		if (Reset)
			state <= 4'h0;
		else
			state <= nextstate;
	
	assign {we0, SetValid, SetDirty, MWE, BlockOffset} = ctls;
	assign WE = we0 & ~(initstate & Hit & Suspense);

	// 有限状态机状态转移
	always @(*)
		case (state)
			4'h0:
				if (Hit | ~En)
					/* if (Suspense | ~En)
					nextstate <= 4'h9;
					else */
					nextstate <= 4'h0;
				else
					if (Dirty)
					nextstate <= 4'h5;
					else
					nextstate <= 4'h1;
			4'h1:
				if (MReady)
					nextstate <= 4'h2;
				else
					nextstate <= state;
			4'h2:
				if (MReady)
					nextstate <= 4'h3;
				else
					nextstate <= state;
			4'h3:
				if (MReady)
					nextstate <= 4'h4;
				else
					nextstate <= state;
			4'h4:
				if (MReady)
					nextstate <= 4'h9;
				else
					nextstate <= state;
			4'h5:
				if (MReady)
					nextstate <= 4'h6;
				else
					nextstate <= state;
			4'h6:
				if (MReady)
					nextstate <= 4'h7;
				else
					nextstate <= state;
			4'h7:
				if (MReady)
					nextstate <= 4'h8;
				else
					nextstate <= state;
			4'h8:
				if (MReady)
					nextstate <= 4'h1;
				else
					nextstate <= state;
			4'h9:
				if (Suspense | ~En)
					nextstate <= state;
				else
					nextstate <= 4'h0;
			default:
				nextstate <= 4'bxxxx;
		endcase

	// 有限状态机输出
	always @(*)
		if (state == 4'h0 | state == 4'h9)
			OffsetSW <= 1'b1;
		else
			OffsetSW <= 1'b0;
	
	assign initstate = ~(|state);
	assign Init = initstate & En;

	always @(*)
		case (state)
			4'h0:
				if (Hit)
					if (CWE)
					ctls <= 6'b1110xx;
					else
					ctls <= 6'b0xx0xx;
				else
					ctls <= 6'b0xx0xx;
			4'h1:
				if (MReady)
					ctls <= 6'b100000;
				else
					ctls <= 6'b0xx0xx;
			4'h2:
				if (MReady)
					ctls <= 6'b100001;
				else
					ctls <= 6'b0xx0xx;
			4'h3:
				if (MReady)
					ctls <= 6'b100010;
				else
					ctls <= 6'b0xx0xx;
			4'h4:
				if (MReady)
					ctls <= 6'b110011;
				else
					ctls <= 6'b0xx0xx;
			4'h5:
				if (MReady)
					ctls <= 6'b0xx101;
				else
					ctls <= 6'b0xx100;
			4'h6:
				if (MReady)
					ctls <= 6'b0xx110;
				else
					ctls <= 6'b0xx101;
			4'h7:
				if (MReady)
					ctls <= 6'b0xx111;
				else
					ctls <= 6'b0xx110;
			4'h8:
				if (MReady)
					ctls <= 6'b0xx0xx;
				else
					ctls <= 6'b0xx111;
			4'h9:
				if (Suspense)
					ctls <= 6'b0xx0xx;
				else
					if (Hit & CWE)
					ctls <= 6'b1110xx;
						else
					ctls <= 6'b0xx0xx;
		endcase

endmodule
