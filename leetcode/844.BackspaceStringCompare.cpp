/*

Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

 

Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".
Example 2:

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".
Example 3:

Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".
 

Constraints:

1 <= s.length, t.length <= 200
s and t only contain lowercase letters and '#' characters.


*/

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> stk1;
        stack<char> stk2;
        for(auto i : s){
            if(stk1.empty() and i=='#'){
                continue;
            }else{
                if(i=='#'){
                    stk1.pop();
                }else{
                    stk1.push(i);
                }
            }
        }
        for(auto i : t){
            if(stk2.empty() and i=='#'){
                continue;
            }else{
                if(i=='#'){
                    stk2.pop();
                }else{
                    stk2.push(i);
                }
            }
        }
        while(!stk1.empty() and !stk2.empty()){
            if(stk1.top()!=stk2.top()) return false;
            stk1.pop();
            stk2.pop();
        }
        if(!stk1.empty() or !stk2.empty()){
            return false;
        }
        return true;
        
    }
};
