/*

Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.

 

Example 1:

Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

Example 2:

Input: word1 = "leetcode", word2 = "etco"
Output: 4

 

Constraints:

    1 <= word1.length, word2.length <= 500
    word1 and word2 consist of only lowercase English letters.





*/


class Solution {
public:
    int helper(string s1, string s2, int i, int j, unordered_map<string, int>& dp){
        if(i<0 or j<0) return 0;
        if(dp.find(to_string(i)+"|"+to_string(j))!=dp.end()) return dp[to_string(i)+"|"+to_string(j)];
        if(s1[i]==s2[j]){
            return dp[to_string(i)+"|"+to_string(j)]=1+helper(s1, s2, i-1, j-1, dp);
        }else{
            return dp[to_string(i)+"|"+to_string(j)]=max(helper(s1, s2, i-1, j, dp), helper(s1, s2, i, j-1, dp));
        }
    }
    int minDistance(string s1, string s2) {
        unordered_map<string, int> dp;
        return ((s1.size()+s2.size())-(2*helper(s1, s2, s1.size()-1, s2.size()-1, dp)));
    }
};
