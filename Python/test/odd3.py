#!/usr/bin/python

import sys

print(len(sys.argv))
if len(sys.argv) == 1:
	print('error')
	sys.exit()

flag = sys.argv[1]

if flag == '-a':
	line = ''
	a = 1
	while a <= 100:
		if a % 2 == 1 and a < 99:
			line += str(a) + ', '
		elif a % 2 == 1:
			line += str(a)
		a += 1
	print(line)

if flag == '-d':
	line = ''
	a = 100
	while a >= 1:
		if a % 2 == 1 and a > 1:
			line += str(a) + ', '
		elif a % 2 == 1:
			line += str(a)
		a -= 1
	print(line)
