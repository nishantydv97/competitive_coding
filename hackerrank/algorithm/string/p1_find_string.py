'''

In this challenge, the user enters a string and a substring. You have to print the number of times that the substring occurs in the given string. String traversal will take place from left to right, not from right to left.

NOTE: String letters are case-sensitive.

Input Format

The first line of input contains the original string. The next line contains the substring.

Constraints


Each character in the string is an ascii character.

Output Format

Output the integer number indicating the total number of occurrences of the substring in the original string.

Sample Input

ABCDCDC
CDC

Sample Output

2

'''
def count_substring(string, sub_string):
    flag=0
    cnt=0
    l=0
#    print(len(string)-len(sub_string))
    for i in range(len(string)-len(sub_string)+1):
        k=i
        for j in range(len(sub_string)):
#            print("val of j is :",j,"val of k in :",k)
            if sub_string[j]==string[k]:
                flag=1
            if flag==1:
#                print(string[k])
                cnt+=1
#                print(cnt)
#                print("position in string is",k)
                flag=0
            else:
                cnt=0
            k+=1
            if cnt==(len(sub_string)):
                l+=1
#               print("value of l is ",l)
                cnt=0
    return l

if __name__ == '__main__':
    string = input().strip()
    sub_string = input().strip()
    
    count = count_substring(string, sub_string)
    print(count)
