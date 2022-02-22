/*

Given a string columnTitle that represents the column title as appear in an Excel sheet, return its corresponding column number.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
 

Example 1:

Input: columnTitle = "A"
Output: 1
Example 2:

Input: columnTitle = "AB"
Output: 28
Example 3:

Input: columnTitle = "ZY"
Output: 701
 

Constraints:

1 <= columnTitle.length <= 7
columnTitle consists only of uppercase English letters.
columnTitle is in the range ["A", "FXSHRXW"].
Accepted
478,294
Submissions
793,271

*/


class Solution {
public:
    int titleToNumber(string columnTitle) {
        unordered_map<char, int> ump;
        for(char i ='A'; i<='Z'; i++){
            ump[i]=i-'A'+1;
        }
        int i=columnTitle.size()-1;
        int num=0;
        int j=0;
        while(i>=0){
            num+=(pow(26,j)*ump[columnTitle[i]]);
            i--;
            j++;
        }
        return num;
    }
};
