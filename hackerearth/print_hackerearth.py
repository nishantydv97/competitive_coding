    n=int(input())
    ar=input()
    cnt=[]
    cnt.append((ar.count('h'))/2)
    cnt.append((ar.count('a'))/2)
    cnt.append((ar.count('c')))
    cnt.append((ar.count('k')))
    cnt.append((ar.count('e'))/2)
    cnt.append((ar.count('r'))/2)
    cnt.append((ar.count('t')))
    z=int(min(cnt))
    print(z)