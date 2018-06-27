for n in range(int(input())):
    t=input()
    l=len(t)
    if l>10:
        print(t[0],end='')
        print(l-2,end='')
        print(t[l-1])
    else:
        print(t)

