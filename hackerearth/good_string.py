s=input().strip()
cnt=0
b=''
b+=s[0]
for x in range(len(s)):
	if(s[x] not in b):
		b+=s[x]
#print(b)
print(len(s)-len(b))
