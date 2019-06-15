	assign ready = (~iEn | iHit) & (~dEn | dHit);
	assign cpuclk = cpumask & CLK;
	assign cpumask = ready & state;
	assign suspense = ~ready;
