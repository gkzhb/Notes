`timescale 1ns / 1ps

module replacecontroller(
	input CLK, Reset, Init,
	input [3:0] Valid, Eq,
	output reg [1:0] S,
	output wire Hit);

	wire [1:0] count[3:0];
	wire [3:0] target, toadd, toadd1, clr;
	wire [1:0] s0, s1, s00, s01, snext;

	wire [1:0] cntnext[3:0];
	assign Hit = |Eq;
	assign target[0] = &count[0] & Valid[0];
	assign target[1] = &count[1] & Valid[1];
	assign target[2] = &count[2] & Valid[2];
	assign target[3] = &count[3] & Valid[3];

	priorencode4to2 enc0(~Valid, s00);
	encode4to2 enc1(Eq, s01);
	encode4to2 enc2(target, s1);
	
	mux2 #(2) s0mux(s00, s01, Hit, s0);
	mux2 #(2) targetmux(s0, s1, &Valid & ~Hit, snext);

	always @(negedge CLK)
		if (Init)
			S <= snext;
		else
			S <= S;

	assign toadd1[0] = (count[snext] > count[0]) ? 1 : 0;
	assign toadd1[1] = (count[snext] > count[1]) ? 1 : 0;
	assign toadd1[2] = (count[snext] > count[2]) ? 1 : 0;
	assign toadd1[3] = (count[snext] > count[3]) ? 1 : 0;


	mux2 #(4) addmux(Valid, toadd1, Hit, toadd);

	flopenrc #(2) cnt0(CLK, Reset, clr[0], Init, cntnext[0], count[0]);
	flopenrc #(2) cnt1(CLK, Reset, clr[1], Init, cntnext[1], count[1]);
	flopenrc #(2) cnt2(CLK, Reset, clr[2], Init, cntnext[2], count[2]);
	flopenrc #(2) cnt3(CLK, Reset, clr[3], Init, cntnext[3], count[3]);

	adder #(2) countadd0(count[0], {1'b0, toadd[0]}, cntnext[0]);
	adder #(2) countadd1(count[1], {1'b0, toadd[1]}, cntnext[1]);
	adder #(2) countadd2(count[2], {1'b0, toadd[2]}, cntnext[2]);
	adder #(2) countadd3(count[3], {1'b0, toadd[3]}, cntnext[3]);

	decode2to4 #(1) clrdec(Init, snext, clr[0], clr[1], clr[2], clr[3]);

endmodule
