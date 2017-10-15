n = int(input().strip())
scores = [int(scores_temp) for scores_temp in input().strip().split(' ')]
m = int(input().strip())
alice = [int(alice_temp) for alice_temp in input().strip().split(' ')]
scores=list(set(scores))
scores.sort(key=int)
n=len(scores)
rank=n+1
s_index=0
for a in alice:
  while s_index<n and a>=scores[s_index]:
    s_index+=1
    rank-=1
  print(rank)
