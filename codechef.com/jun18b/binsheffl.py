'''

Chef has two integers A and B. He can perform the following operation on A an arbitrary number of times (including zero):

write A as a binary number with an arbitrary number of leading zeroes (possibly without any)
shuffle the binary digits of A in an arbitrary way, obtaining a number s
replace A by s+1
Chef is wondering about the minimum number of operations he has to perform on A in order to obtain B. Compute this number or determine that it is impossible.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains two space-separated integers A and B.
Output
For each test case, print a single line containing one integer — the minimum number of operations or −1 if it is impossible to obtain B from A.

Constraints
1≤T≤105
0≤A,B≤1018
Subtasks
Subtask #1 (20 points): A,B≤27
Subtask #2 (80 points): original constraints

Example Input
2
2 4
1 5
Example Output
2
1
Explanation
Example case 1: One optimal solution is to not shuffle anything, so Chef just adds 1 twice.

Example case 2: We can obtain 5 from 1 in one operation.



'''



import cmath
import math
for _ in range(int(input())):
    x,y=map(int,input().strip().split())
    a=x
    b=y
    x=bin(x)[2:]
    y=bin(y-1)[2:]
#    print(x,y)
    cnt1=x.count('1')
    cnt2=y.count('1')
    if(a==b):
        print(0)
    elif(b==0):
        print(-1)
    elif(b==1):
        if(a==0):
            print(1)
        else:
            print(-1)
    elif(cnt1==cnt2):
        print(1)
    elif(cnt1<cnt2):
        m=cnt2-cnt1+1
        if(b>a):
            if(m<b-a):
                m=m
            else:
                m=b-a
        print(m)
    else:
        print(2)  
