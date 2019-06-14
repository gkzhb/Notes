module block(
	input CLK,
	input Reset,
	input [1:0] Offset,
	input WE, SetValid, SetDirty,
	input [25:0] SetTag,
	input [31:0] WD,
	output reg Valid,
	output Dirty,
	output reg [25:0] Tag,
	output [31:0] RD);
