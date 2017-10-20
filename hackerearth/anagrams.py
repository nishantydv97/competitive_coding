'''

also asked in inmobi

'''
from collections import Counter
for i in range(int(input())):
	a=input()
	b=input()
	cnt=0
	a1=''.join(set(a))
	b1=''.join(set(b))
#	print(a)
#	print(b)
	for x in a1:
		if x not in b1:
			cnt=cnt+a.count(x)
#			print("cnt in 1 is ",cnt)
		else:
			cnt=cnt+abs(a.count(x)-b.count(x))
	for y in b1:
		if y not in a1:
			cnt=cnt+b.count(y)
#			print("cnt in 2 is ",cnt)
		else:
			cnt=cnt+abs(a.count(y)-b.count(y))
	print(cnt)

