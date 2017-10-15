#!/bin/python3

import sys

def getMoneySpent(keyboards, drives, s):
    # Complete this function
    max=0
    f=0
    for x in keyboards:
        for y in drives:
            if x+y<=s and x+y>max:
                f=1
                max=x+y
    if f==1:
        return (max)
    else:
        return (-1)
    
s,n,m = input().strip().split(' ')
s,n,m = [int(s),int(n),int(m)]
keyboards = list(map(int, input().strip().split(' ')))
drives = list(map(int, input().strip().split(' ')))
#  The maximum amount of money she can spend on a keyboard and USB drive, or -1 if she can't purchase both items
moneySpent = getMoneySpent(keyboards, drives, s)
print(moneySpent)
