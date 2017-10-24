#!/bin/python3
import sys
cnt=0
s = input().strip()
for i in s:
    if ord(i)>64 and ord(i)<91:
        cnt+=1
print(cnt+1)

