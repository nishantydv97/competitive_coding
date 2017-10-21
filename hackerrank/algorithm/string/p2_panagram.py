s=input()
l=[]
#print(s)
for i in s:
#    print(i)
    z=ord(i)
    if z>90:
        z-=32
    if z not in l:
        l.append(z)
if 32 in l:
    l.remove(32)
if len(l)==26:
    print("pangram")
else:
    print("not pangram")
#print(len(l))
#print(l)
