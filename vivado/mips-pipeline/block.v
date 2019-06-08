`timescale 1ns / 1ps

module block(
	input CLK,
	input Reset,
	input [1:0] Offset,
	input WE, SetValid, SetDirty,
	input [25:0] SetTag,
	input [31:0] WD,
	output reg Valid, Dirty,
	output reg [25:0] Tag,
	output [31:0] RD);

	reg [31:0] data[3:0];

	assign RD = data[Offset];

	always @(posedge CLK, posedge Reset)
		if (Reset)
			Valid <= 1'b0;
		else
			if (WE)
			begin
				data[Offset] <= WD;
				Dirty <= SetDirty;
				Valid <= SetValid;
				Tag <= SetTag;
			end
			else
			begin
				data[Offset] <= data[Offset];
				Dirty <= Dirty;
				Valid <= Valid;
				Tag <= Tag;
			end

endmodule
