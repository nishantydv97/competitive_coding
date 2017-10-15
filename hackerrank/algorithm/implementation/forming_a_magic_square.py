import sys
import itertools
import operator

def gen_magic_list():
    final_list = []
    pre_list = []
    
    gen = list(itertools.permutations(range(1,10)))
    for gen_list in gen:
       pre_list.append([list(gen_list[x:x+3]) for x in range(0,9,3)])
    
    for check_list in pre_list:
        verifi_list = []
        verifi_list.extend([sum(row_list[col] for row_list in check_list) for col in range(3)])
        verifi_list.extend(sum(row_list) for row_list in check_list)
        verifi_list.append(sum([element[i] for element, i  in zip(check_list,range(len(check_list)))]))
        verifi_list.append(sum([element[i] for element, i  in zip(check_list,range(len(check_list)-1, -1, -1))]))
        if len(set(verifi_list)) == 1:
            final_list.append(check_list)
    return final_list
    
s = []
cost_list = []
for s_i in range(3):
   s_t = [int(s_temp) for s_temp in input().strip().split(' ')]
   s.append(s_t)
magic_lists = gen_magic_list()

for magic_list in magic_lists:
    cost = 0
    for m_row , s_row in zip(magic_list, s):
        for m_el, s_el in zip(m_row, s_row):
            if m_el != s_el:
                cost += abs(m_el-s_el)
    cost_list.append(cost)
    
print(min(cost_list))
