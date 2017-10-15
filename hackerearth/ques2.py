n=[int(x) for x in input().strip().split()]
ar=[int(y) for y in input().strip().split()]
f=0
for z in ar:
	if(z<n[1] or z>n[2]):
		f=1
if f==0:
	print("YES")
else:
	print("NO")
