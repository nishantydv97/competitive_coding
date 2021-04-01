/*

Given a string s, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them causing the left and the right side of the deleted substring to concatenate together.

We repeatedly make k duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made.

It is guaranteed that the answer is unique.

 

Example 1:

Input: s = "abcd", k = 2
Output: "abcd"
Explanation: There's nothing to delete.
Example 2:

Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
Explanation: 
First delete "eee" and "ccc", get "ddbbbdaa"
Then delete "bbb", get "dddaa"
Finally delete "ddd", get "aa"
Example 3:

Input: s = "pbbcggttciiippooaais", k = 2
Output: "ps"
 

Constraints:

1 <= s.length <= 10^5
2 <= k <= 10^4
s only contains lower case English letters.




*/





class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<int, int>> stk;
        for(auto i : s){
            if(stk.empty()){
                stk.push(make_pair(i, 1));
            }else{
                if(stk.top().first==i){
                    if(stk.top().second==k-1){
                        stk.pop();
                    }else{
                        stk.top().second++;
                    }
                }else{
                    stk.push(make_pair(i, 1));
                }
            }
        }
        string ans="";
        while(!stk.empty()){
            char c=stk.top().first;
            int cnt=stk.top().second;
            while(cnt--) ans=c+ans;
            stk.pop();
        }
        return ans;
    }
};
