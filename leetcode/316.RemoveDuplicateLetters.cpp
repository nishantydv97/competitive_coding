/*
Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

 

Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"
 

Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.
 

Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

Accepted
183,851
Submissions
421,570


*/


class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastDist(26, -1);
        vector<int> vis(26, 0);
        for(int i=0; i<s.size(); i++){
            lastDist[s[i]-'a']=i;
        }
        stack<char> stk;
        for(int i=0; i<s.size(); i++){
            if(vis[s[i]-'a']) continue;
            while(!stk.empty() and lastDist[stk.top()-'a']>i and stk.top()>s[i]){
                vis[stk.top()-'a']=0;
                stk.pop();
            }
            stk.push(s[i]);
            vis[s[i]-'a']=1;
        }
        string res="";
        while(!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
        
    }
};
