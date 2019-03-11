`timescale 1ns / 1ps

module ALU(
	input [31:0] A,
	input [31:0] B,
	input [2:0] Alucont,
	output reg [31:0] Result,
	output Zero
	);

	wire [31:0] f;

	AddSub addsub(.A(A), .B(B), .Sign(Alucont[2]), .S(f));
	assign Zero = ~(| Result);

	always @(*)
	begin
		case(Alucont)
			2'b000: Result = A & B;
			2'b001: Result = A | B;
			2'b010: Result = f;
			2'b100: Result = A & (~B);
			2'b101: Result = A | (~B);
			2'b110: Result = f;
			2'b111: Result = {31'b000_0000_0000_0000_0000_0000_0000_0000, f[31]};
			default: Result = 31'b0;
		endcase
	end

endmodule 

// 显示测试工具 单独做一个模块
// 所有的 case 一定要加 default
// 所有的 if 一定要加 else
// 小端法
// DDL: 第五周
