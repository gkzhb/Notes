#!/usr/bin/python

import sys
n = 0
with open(str(sys.argv[1])) as f:
	lines = f.readlines()
	while n < len(lines):
		if list(lines[n])[0] == sys.argv[2]:
			print(lines[n]),
		n += 1

