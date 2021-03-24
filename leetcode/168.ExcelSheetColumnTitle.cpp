/*

Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

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

Input: columnNumber = 1
Output: "A"
Example 2:

Input: columnNumber = 28
Output: "AB"
Example 3:

Input: columnNumber = 701
Output: "ZY"
Example 4:

Input: columnNumber = 2147483647
Output: "FXSHRXW"



*/


class Solution {
public:
    string convertToTitle(int columnNumber) {
        vector<int> base26;
        while(columnNumber>0){
            base26.push_back(columnNumber%26==0 ? 26 : columnNumber%26);
            bool flag=0;
            flag=columnNumber%26==0;
            columnNumber/=26;
            if(flag) columnNumber-=1;
        }
        reverse(base26.begin(), base26.end());
        string ans;
        for(auto i : base26){
            ans+=('A'+i-1);
        }
        return ans;
    }
};
