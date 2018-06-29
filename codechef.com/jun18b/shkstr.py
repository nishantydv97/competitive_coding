'''

Sheokand loves strings. Chef has N strings S1,S2,…,SN which he wants to give to Sheokand; however, he doesn't want to give them away for free, so Sheokand must first correctly answer Q queries Chef asks him.

In each query, Chef tells Sheokand an integer R and a string P. Consider Chef's strings S1 through SR. Out of these strings, consider all strings such that their longest common prefix with P is maximum possible. Sheokand should find the lexicographically smallest of these strings.

Sheokand is busy with his exams. Can you solve the queries for him?

Input
The first line of the input contains a single integer N.
N lines follow. For each valid i, the i-th of these lines contains Chef's string Si.
The next line contains a single integer Q.
The following Q lines describe queries. Each of these lines contains an interger R, followed by a space and a string P.
Output
For each query, print a single line containing the string that satisfies the required conditions — the answer to that query.

Constraints
1≤N≤100,000
1≤|Si|≤10 for each valid i
1≤Q≤100,000
1≤R≤N
1≤|P|≤10
Subtasks
Subtask #1 (30 points): 1≤N,R≤1,000
Subtask #2 (70 points): original constraints

Example Input
4
abcd
abce
abcdex
abcde
3
3 abcy
3 abcde
4 abcde
Example Output
abcd
abcdex
abcde
Explanation
Query 1: For strings S1 through S3, the longest common prefix is always "abc", but "abcd" is the lexicographically smallest of these three strings.

Query 2: For strings S1 through S3, the longest common prefix with maximum length is "abcde" and the only string for which it is the LCP is "abcdex", so this is the answer.

Query 3: For strings S1 through S4, the longest common prefix with maximum length is "abcde"; it is the LCP for strings "abcdex" and "abcde", but "abcde" is the lexicographically smaller string, so it is the answer.


'''


def commonprefix(s,r,p):
    t=s[0:r]
    l=[]
    m=[]
    z1=['']
    z2=['']
    for i in range(len(p)):
        g=p[0:i+1]
        for j in range(len(t)):
            if(g==t[j][0:i+1]):
                l.append(g)
                m.append(t[j])
#        print(l,m)
        if(len(l)>0):
            if(len(z1[0])<=len(l[0])):
                z1=l[:]
                l=l[0:0]
                z2=m[:]
                m=m[0:0]
#        l.append('#')
#        m.append('#')
    return(z2)
s=[]
for _ in range(int(input().strip())):
    s.append(input().strip())
 
for _ in range(int(input().strip())):
    r,p=input().strip().split()
    r=int(r)
    l=(commonprefix(s,r,p))
    if(len(l[0])==0):
        print(min(s[0:r]))
    else:
        print(min(l))
