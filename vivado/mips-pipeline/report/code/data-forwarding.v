	// Decode 阶段数据转发
	mux2 #(32) forwardadmux(srcAD, ALUOutM, forwardaD, srcA2D);
	mux2 #(32) forwardbdmux(srcBD, ALUOutM, forwardbD, srcB2D);
	// Execute 阶段数据转发
	mux4 #(32) forwardaemux(srcAE, resultW, ALUOutM, 32'b0, forwardaE, srcA2E);
	mux4 #(32) forwardbemux(srcBE, resultW, ALUOutM, 32'b0, forwardbE, srcB2E);
