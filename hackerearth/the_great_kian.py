n=int(input())
ar=[int(x) for x in input().strip().split(' ')]
x=0
sum1=0
while x<n:
    sum1+=ar[x]
    x+=3
x=1
sum2=0
while x<n:
    sum2+=ar[x]
    x+=3
x=2
sum3=0
while x<n:
    sum3+=ar[x]
    x+=3
print(sum1,sum2,sum3)
