#!/bin/python3

import sys

count=0
n = int(input().strip())
c = [int(c_temp) for c_temp in input().strip().split(' ')]
c.sort()
for i in range(0,n-1):
    if c[i]==c[i+1]:
        c[i+1]=0
        count+=1 
print(count)
