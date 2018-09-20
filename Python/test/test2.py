#!/usr/bin/python

# import sys

a = int(input('starting number: '))
line = ''

while a != 1:
    line += str(a) + ', '
    # print(a)
    # print(a % 2)
    if a % 2 == 0:
        a = a/2
    else:
        a = a*3+1

line += '1'
print(line)