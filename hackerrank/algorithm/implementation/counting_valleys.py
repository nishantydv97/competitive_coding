n = int(input())
steps = input()

level = 0
valley = 0

if steps[0] == "U":
    level+=1
else:
    level-=1
    

for i in range(1,len(steps)):
    if steps[i] == "U":
        level += 1
    else:
        level -= 1
        
    if level == 0 and steps[i]=="U":
        valley += 1
    
            
print(valley)
