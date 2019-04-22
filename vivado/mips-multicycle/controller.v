`timescale 1ns / 1ps

module controller(
	input CLK, Reset,
	input [5:0] Op, Funct,
	input Zero,
	output IorD, MemWrite, IRWrite, RegDst, MemToReg, ALUSrcA, RegWrite, PCEn,
	output reg ExtOp,
	output reg [2:0] ALUCtl,
	output [1:0] ALUSrcB, PCSrc,

	output [2:0] AluCtl);

	// FSM State Encode
	parameter FETCH   = 4'b0000;	// Fetch instruction
	parameter DECODE  = 4'b0001;	// Decode
	parameter MEMADR  = 4'b0010;	// Calculate memory address
	parameter MEMRD   = 4'b0011;	// LW: Memory read
	parameter MEMWB   = 4'b0100;	// LW: Memory write back to reg
	parameter MEMWR   = 4'b0101;	// SW: Memory write
	parameter REX     = 4'b0110;	// R-Type: Execute
	parameter RWB     = 4'b0111;	// R-Type: Write back to reg
	parameter BEX     = 4'b1000;	// BEQ & BNE Execute
	parameter IEX     = 4'b1001;	// I-Type: Execute
	parameter IWB     = 4'b1010;	// I-Type: Write back to reg
	parameter JEX     = 4'b1011;	// Jump: Execute

	// Op Code
	parameter LW    = 6'b10_0011;
	parameter SW    = 6'b10_1011;
	parameter RTYPE = 6'b00_0000;
	parameter BEQ   = 6'b00_0100;
	parameter BNE   = 6'b00_0101;
	parameter J     = 6'b00_0010;
	// Op Code for ITYPE
	parameter ADDI  = 6'b00_1000;
	parameter ANDI  = 6'b00_1100;
	parameter SLTI  = 6'b00_1010;
	parameter ORI   = 6'b00_1101;

	reg [3:0] state, nextstate;
	reg [16:0] ctls;
	wire [2:0] AluOp0, AluOp1;
	wire RType;
	wire bne;

	assign {PCWrite, MemWrite, IRWrite, RegWrite, AluSrcA, Branch, IorD, MemToReg, RegDst, AluSrcB, PCSrc, AluOp0} = ctls;
	assign AluCtl = AluOp0 | AluOp1;
	assign bne = Op[0];		// beq bne Op Code 差别在于最低位
	assign ExtOp0 = 1;
	assign PCEn = (Zero ^ bne) & Branch & PCWrite;

	aludec ad(Op, Funct, AluOp1, ExtOp1);

	always @(posedge CLK, posedge Reset)
		if (Reset)
			state <= FETCH;
		else
			state <= nextstate;
	
	// Finite State Machine, 状态转移
	always @(*)
		case(state)
			FETCH: nextstate = DECODE;
			DECODE:
				case(Op)
					LW:      nextstate = MEMADR;
					SW:      nextstate = MEMADR;
					BEQ:     nextstate = BEX;
					BNE:     nextstate = BEX;
					J:       nextstate = JEX;
					RTYPE:   nextstate = REX;
					ADDI:    nextstate = IEX;
					ANDI:    nextstate = IEX;
					SLTI:    nextstate = IEX;
					ORI:     nextstate = IEX;
					default: nextstate = 4'bx;
				endcase
			MEMADR:
				case(Op)
					LW:      nextstate = MEMRD;
					SW:      nextstate = MEMWR;
					default: nextstate = 4'bx;
				endcase
			MEMRD:   nextstate = MEMWB;
			MEMWB:   nextstate = FETCH;
			MEMWR:   nextstate = FETCH;
			REX:     nextstate = RWB;
			RWB:     nextstate = FETCH;
			IEX:     nextstate = IWB;
			IWB:     nextstate = FETCH;
			JEX:     nextstate = FETCH;
			BEX:     nextstate = FETCH;
			default: nextstate = 4'bx;
		endcase
	
	always @(*)
		if (state == REX || state == IEX)
			{AluCtl, ExtOp} <= {AluOp1, ExtOp1};
		else
			{AluCtl, ExtOp} <= {AluOp0, ExtOp0};
	
	// 状态输出
	always @(*)
		case(state)
			FETCH: ctls = 16'b0;
		endcase
endmodule
