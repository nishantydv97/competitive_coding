s=input()
n=int(input())
z=['-','.',';','%']
for x in range(len(s)):
	if s[x] not in z:
		if ord(s[x]) in range(65,91):
			t=ord(s[x])
			t+=n
			if t>90:
				while(t not in range(65,91)):
					t=t-90+65-1
			print(chr(t),end='')
		elif ord(s[x]) in range(97,123):
			t=ord(s[x])
			t+=n
			if t>122:
				while(t not in range(97,123)):
					t=t-122+97-1
			print(chr(t),end='')
		elif ord(s[x]) in range(48,58):
			t=ord(s[x])
			t+=n
			if t>57:
				while(t not in range(48,58)):
					t=t-57+48-1
			print(chr(t),end='')
	else:
		print(s[x],end='')
