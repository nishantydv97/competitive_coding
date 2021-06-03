/*

Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

 

Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we don't need any insertions.

Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".

Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".

Example 4:

Input: s = "g"
Output: 0

Example 5:

Input: s = "no"
Output: 1

 

Constraints:

    1 <= s.length <= 500
    All characters of s are lower case English letters.





*/

class Solution {
public:
    vector<vector<int>>dp;
    int helper(string &s, int i, int j, vector<vector<int>>& dp){
        
        int n=s.size();
        if(i>=n or i<0 or j>=n or j<0) return 1e8;
        //cout<<i<<" "<<j<<endl;
        if(i==j) return 0;
        if(i+1==j){
            if(s[i]==s[j]) return 0;
            else{
                return 1;
            }
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]){
            return dp[i][j]=helper(s, i+1, j-1, dp);
        }else{
            return dp[i][j]=1+min(helper(s, i+1, j, dp), helper(s, i, j-1, dp));
        }
    }
    int minInsertions(string s) {
        int n=s.size();
        //vector<vector<int>> dp(n, vector<int>(n, -1));
        dp.resize(s.size(),vector<int>(s.size(),-1));
        int x=helper(s, 0, s.size()-1, dp);
        return x;
    }
};
