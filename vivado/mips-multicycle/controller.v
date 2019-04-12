`timescale 1ns / 1ps

module controller(
	input CLK, Reset,
	input [5:0] Op, Funct
	input Zero,
	output IorD,
	output [2:0] AluOp);			// TODO AluOp or AluCtl ?

	// FSM State Encode
	parameter FETCH   = 4'b0000;	// Fetch instruction
	parameter DECODE  = 4'b0001;	// Decode
	parameter MEMADR  = 4'b0010;	// Calculate memory address
	parameter MEMRD   = 4'b0011;	// LW: Memory read
	parameter MEMWB   = 4'b0100;	// LW: Memory write back to reg
	parameter MEMWR   = 4'b0101;	// SW: Memory write
	parameter RTYPEEX = 4'b0110;	// R-Type: Execute
	parameter RTYPEWB = 4'b0111;	// R-Type: Write back to reg
	parameter BEX     = 4'b1000;	// BEQ & BNE
	parameter ITYPEEX = 4'b1001;	// I-Type: Execute
	parameter ITYPEWB = 4'b1010;	// I-Type: Write back to reg
	parameter JEX     = 4'b1011;	// Jump: Execute
	parameter TMP     = 4'b1100;	// None

	// Op Code
	parameter LW    = 6'b10_0011;
	parameter SW    = 6'b10_1011;
	parameter RTYPE = 6'b00_0000;
	parameter BEQ   = 6'b00_0100;
	parameter ADDI  = 6'b00_1000;
	parameter J     = 6'b00_0010;

	reg [3:0] state, nextstate;
	reg [14:0] ctls;
	wire [2:0] AluOp0, AluOp2;
	reg [2:0] AluOp1;
	wire RType

	assign {PCWrite, MemWrite, IRWrite, RegWrite, AluSrcA, Branch, IorD, MemToReg, RegDst, AluSrcB, PCSrc, AluOp0} = ctls;
	assign AluOp = AluOp0 | AluOp1;

	aludec ad(Funct, AluOp2);

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
					RTYPE:   nextstate = RTYPEEX;
					BEQ:     nextstate = BEQEX;
					ADDI:    nextstate = ITYPEEX;
					J:       nextstate = JEX;
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
			RTYPEEX: nextstate = RTYPEWB;
			RTYPEWB: nextstate = FETCH;
			ITYPEEX: nextstate = ITYPEWB;
			ITYPEWB: nextstate = FETCH;
			JEX:     nextstate = FETCH;
			default: nextstate = 4'bx;
		endcase
	
	// ITYPE EXECUTE 阶段 AluOp 控制
	always @(*)
		if (state == ITYPEEX)
			case(Op)
				ADDI: AluOp1 <= 3'b000;
			endcase
		else
			if (state == RTYPEEX)
				AluOp1 <= AluOp2;
			else
				AluOp1 <= 3'b000;

	// 状态输出
	always @(*)
		case(state)
			FETCH: ctls = 15'b0;
		endcase
endmodule
