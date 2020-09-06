/*

Given s1, s2, and s3, find whether s3 is formed by the interleaving of s1 and s2.

 

Example 1:


Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
Example 3:

Input: s1 = "", s2 = "", s3 = ""
Output: true
 

Constraints:

0 <= s1.length, s2.length <= 100
0 <= s3.length <= 200
s1, s2, and s3 consist of lower-case English letters.
Given s1, s2, and s3, find whether s3 is formed by the interleaving of s1 and s2.

 

Example 1:


Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
Example 3:

Input: s1 = "", s2 = "", s3 = ""
Output: true
 

Constraints:

0 <= s1.length, s2.length <= 100
0 <= s3.length <= 200
s1, s2, and s3 consist of lower-case English letters.

*/



class Solution {
public:
    
    bool solve(string s1, string s2, string s3,unordered_map<string, bool> &dp){
        if(s1.empty() and s2.empty() and s3.empty()) return 1;
        if(s3.empty()) return 0;
        string str=s1+"|"+s2+"|"+s3;
        if(dp.count(str)){
            return dp[str];
        }
        bool fi=(!s1.empty()) and s1[0]==s3[0] and solve(s1.substr(1),s2,s3.substr(1), dp);
        bool si=(!s2.empty()) and s2[0]==s3[0] and solve(s1,s2.substr(1),s3.substr(1), dp);
        return dp[str]=(fi or si);
        
    }
    bool isInterleave(string s1, string s2, string s3) {
        unordered_map<string,bool> dp;
        return solve(s1,s2,s3,dp);
    }
};

