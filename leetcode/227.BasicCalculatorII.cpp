/*


Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "3+2*2"
Output: 7
Example 2:

Input: s = " 3/2 "
Output: 1
Example 3:

Input: s = " 3+5 / 2 "
Output: 5
 

Constraints:

1 <= s.length <= 3 * 105
s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
s represents a valid expression.
All the integers in the expression are non-negative integers in the range [0, 231 - 1].
The answer is guaranteed to fit in a 32-bit integer.



*/

class Solution {
public:
    void solve(list<string>& lst, string s){
        string k="";
        for(int i=0; i<s.size(); i++){
            if(s[i]==' ') continue;
            k="";
            while(i<s.size() and s[i]!='*' and s[i]!='/' and s[i]!='-' and s[i]!='+'){
                if(s[i]==' ') {i++;continue;}
                k+=s[i];
                i++;
            }
            if(i>=s.size()) break;
            lst.push_back(k);
            string k1="";
            k1+=s[i];
            lst.push_back(k1);
        }
        lst.push_back(k);
        
    }
    void helper(list<string>& lst, string s1, string s2){
        list<string> :: iterator it= lst.begin();
        while(it!=lst.end()){
            if(*it==s1 or *it==s2){
                auto j=it;
                j--;
                auto k=it;
                k++;
                it++;
                auto g=it;
                g--;
                if(*g=="*"){
                    *it=to_string(stoi(*j)*stoi(*k));
                }else if(*g=="/"){
                    *it=to_string(stoi(*j)/stoi(*k));
                }else if(*g=="-"){
                    *it=to_string(stoi(*j)-stoi(*k));
                }else{
                    *it=to_string(stoi(*j)+stoi(*k));
                }
                
                lst.erase(j);
                auto l=it;
                l--;
                lst.erase(l);
            }
            it++;
        }
    }
    int calculate(string s) {
        //solve mul
        list<string> lst;
        solve(lst, s);
        helper(lst, "*", "/");
        helper(lst, "-", "+");
        return stoi(*lst.begin());
        
    }
};
