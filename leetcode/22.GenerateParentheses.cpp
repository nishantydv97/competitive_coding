/*

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8

*/


class Solution {
public:
    bool checkBalance(string s){
        stack<char> stk;
        for(auto i : s){
            if(stk.empty()){
                stk.push(i);
            }else if(i==')' and stk.top()=='('){
                stk.pop();
            }else{
                stk.push(i);
            }
        }
        if(stk.empty()){
            return true;
        }else{
            return false;
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>  ans;
        string s="";
        for(int i=0;i<n;i++){
            s+='(';
        }
        for(int i=0;i<n;i++){
            s+=')';
        }
        cout<<checkBalance(s)<<endl;
        ans.push_back(s);
        while(next_permutation(s.begin(), s.end())){
            if(checkBalance(s)){
                ans.push_back(s);
            }
        }
        return ans;
        
    }
};
