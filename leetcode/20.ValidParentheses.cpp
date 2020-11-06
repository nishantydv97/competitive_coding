/*


Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
Example 4:

Input: s = "([)]"
Output: false
Example 5:

Input: s = "{[]}"
Output: true

*/



class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> ump = {{'}','{'}, {']', '['}, {')', '('}};
        for(auto i : s){
            if(i=='(' or  i=='{' or i=='['){
                stk.push(i);
            }else{
                if(i==']' and !stk.empty() and stk.top()==ump[i]){
                    stk.pop();
                }
                else if(i==')' and !stk.empty() and stk.top()==ump[i]){
                    stk.pop();
                }
                else if(i=='}' and !stk.empty() and stk.top()==ump[i]){
                    stk.pop();
                }else{
                    stk.push(i);
                }
            }
        }
        return stk.empty();
    }
};
