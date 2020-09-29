/*


Given two strings text1 and text2, return the length of their longest common subsequence.

A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). A common subsequence of two strings is a subsequence that is common to both strings.

 

If there is no common subsequence, return 0.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 

Constraints:

1 <= text1.length <= 1000
1 <= text2.length <= 1000
The input strings consist of lowercase English characters only.


*/

class Solution {
public:
    int helper1(string &s1, string &s2, int m, int n, vector<vector<int>>& dp){
        if(m==s1.size() or n==s2.size()) return 0;
        
        if(dp[m][n]!=-1) return dp[m][n];
        if(s1[m]==s2[n]){
            return dp[m][n]=1+helper1(s1,s2,m+1,n+1,dp);
        }else{
            return dp[m][n]=max(helper1(s1,s2,m+1,n,dp), helper1(s1,s2,m,n+1,dp));
        }
    }
    int helper(string &s1, string &s2, int m, int n, unordered_map<string, int>& dp){
        if(m==s1.size() or n==s2.size()) return 0;
        string key=to_string(m)+"|"+to_string(n);
        if(dp[key]) return dp[key];
        if(s1[m]==s2[n]){
            return dp[key]=1+helper(s1,s2,m+1,n+1,dp);
            
        }else{
            return dp[key]=max(helper(s1,s2,m+1,n,dp), helper(s1,s2,m,n+1,dp));
        }
    }
    
    int longestCommonSubsequence(string s1, string s2) {
        //unordered_map<string, int> dp;
        vector<vector<int>> dp(1001, vector<int>(1001, -1));
        //return helper(s1, s2, 0, 0, dp);
        return helper1(s1, s2, 0, 0, dp);
    }
};
