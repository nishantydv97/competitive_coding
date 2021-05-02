/*

Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Example 4:

Input: s = ""
Output: 0

 

Constraints:

    0 <= s.length <= 5 * 104
    s consists of English letters, digits, symbols and spaces.




*/


#include<bits/stdc++.h>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res=0;
        deque<char> dq;
        unordered_set<char> st;
        for(auto i : s){
            if(st.find(i)==st.end()){
                st.insert(i);
                dq.push_back(i);
            }else{
                while(!dq.empty() and dq.front()!=i){
                    st.erase(dq.front());
                    dq.pop_front();
                }
                st.erase(dq.front());
                dq.pop_front();
                dq.push_back(i);
                st.insert(i);
            }
            res=max(res, (int)st.size());
        }
        return res;
    }
};
