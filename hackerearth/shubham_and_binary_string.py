t = int(input())
for i in range(t):
  l = input()
  n = input()
  count = 0
  for j in n:
      if j == "0":
          count += 1
  print(count)
