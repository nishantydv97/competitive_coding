'''

You are given two points P and Q and an opaque sphere in a three-dimensional space. The point P is not moving, while Q is moving in a straight line with constant velocity. You are also given a direction vector d with the following meaning: the position of Q at time t is Q(t)=Q(0)+d⋅t, where Q(0) is the initial position of Q.

It is guaranteed that Q is not visible from P initially (at time t=0). It is also guaranteed that P and Q do not touch the sphere at any time.

Find the smallest positive time tv when Q is visible from P, i.e. when the line segment connecting points P and Q does not intersect the sphere.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains 13 space-separated integers.
The first three integers Px,Py,Pz denote the coordinates of P.
The next three integers Qx,Qy,Qz denote the initial coordinates of Q.
The next three integers dx,dy,dz denote the components of the direction vector d.
The last four integers cx,cy,cz,r denote the coordinates of the centre of the sphere and its radius.
Output
For each test case, print a single line containing one real number — the time tv. Your answer will be considered correct if its absolute or relative error does not exceed 10−6. It is guaranteed that tv exists and does not exceed 109.

Constraints
1≤T≤105
the absolute values of coordinates of all points do not exceed 2⋅109
1≤r≤109
Subtasks
Subtask #1 (25 points): Pz=Qz=dz=cz=0
Subtask #2 (75 points): original constraints

Example Input
1
3 0 0 -10 -10 0 0 10 0 0 -3 0 3
Example Output
1.0000000000


'''




import cmath
import math
for _ in range(int(input())):
    x1,y1,z1,x2,y2,z2,x3,y3,z3,x4,y4,z4,r=map(int,input().strip().split())
#    print(x1,y1,z1,x2,y2,z2,x3,y3,z3,x4,y4,z4,r)
    a=y4-y1
    b=z4-z1
    c=x4-x1
    d=z2-z1
    e=y2-y1
    f=x2-x1
    g=(a*d-b*e)
    h=(c*d-b*f)
    i=(c*e-a*f)
    j=(a*z3-b*y3)
    k=(c*z3-b*x3)
    l=(c*y3-a*x3)
    A=(j*j+k*k+l*l-r*r*x3*x3-r*r*y3*y3-r*r*z3*z3)
    B=(2*g*j+2*h*k+2*i*l-r*r*2*f*x3-r*r*2*e*y3-r*r*2*d*z3)
    C=(g*g+h*h+i*i-r*r*f*f-r*r*e*e-r*r*d*d)
#    print(A,B,C)
    if(A==0):
        print(format(abs(C/B),'.10f'))
    else:
        dis=(B**2-4*A*C)
        s1=(-B+math.sqrt(dis))
        s2=(-B-math.sqrt(dis))
        s1/=(2*A)
        s2/=(2*A)
#        print(s2,s1)
        if(min(s2,s1)<0):
            print(format(max((s2),(s1)),'.10f'))
        else:
            print(format(min((s2),(s1)),'.10f'))
#    print(format(res,'.10f'))
