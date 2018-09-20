import sys

line = []
words = []
with open(str(sys.argv[2]), 'r') as f:
	while True:
		line = f.readline()
		line = line.strip()
		words = line.split(sep=' ')
		if line == '':
			exit()
		print(words)
