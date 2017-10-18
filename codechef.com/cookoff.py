for t in range(int(input())):
    s = set()
    for n in range(int(input())):
        s.add(input().strip())
    yesno = 'Yes'
    if 'cakewalk' not in s:
        yesno = 'No'
    if 'simple' not in s:
        yesno = 'No'
    if 'easy' not in s:
        yesno = 'No'
    if 'easy-medium' not in s and 'medium' not in s :
        yesno = 'No'
    if 'medium-hard' not in s and 'hard' not in s :
        yesno = 'No'
    print(yesno)

