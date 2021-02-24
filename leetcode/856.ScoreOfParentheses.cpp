/*


Given a balanced parentheses string S, compute the score of the string based on the following rule:

() has score 1
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.
 

Example 1:

Input: "()"
Output: 1
Example 2:

Input: "(())"
Output: 2
Example 3:

Input: "()()"
Output: 2
Example 4:

Input: "(()(()))"
Output: 6
 

Note:

S is a balanced parentheses string, containing only ( and ).
2 <= S.length <= 50


*/


class Solution {
public:
    vector<int> v;
    int calculate(int low, int high, vector<int>& v){
        if(low+1==high) return 1;
        int mid=v[low];
        if(v[low]==high)
            return 2*(calculate(low+1,high-1, v));
        return (calculate(low,mid, v))  + (calculate(mid+1,high, v));
    }
    int scoreOfParentheses(string S) {
        int n=S.size();
        v.resize(n, 0);
        stack<int> stk;
        for(int i=0; i<n; i++){
            if(!stk.empty() and S[i]==')'){
                v[stk.top()]=i;
                stk.pop();
            }else{
                stk.push(i);
            }
        }
        return calculate(0, n-1, v);
    }
};
