/*

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].


*/


class Solution {
public:
    vector<string> solve(unordered_map<char, vector<string>>& ump, string s){
        vector<string> res;
        int len=0;
        stack<string> stk1;
        stack<string> stk2;
        for(auto i : ump[s[len]]){
            cout<<i<<" ";
            stk1.push(i);
        }
        len++;
        while(len<s.size()){
            if(!stk1.empty()){
                while(!stk1.empty()){
                    string k=stk1.top();
                    stk1.pop();
                    for(auto i : ump[s[len]]){
                        stk2.push(k+i);
                    }
                }
            }else{
                while(!stk2.empty()){
                    string k=stk2.top();
                    stk2.pop();
                    for(auto i : ump[s[len]]){
                        stk1.push(k+i);
                    }
                }
            }
            len++;
        }
        if(!stk1.empty()){
            while(!stk1.empty()){
                res.push_back(stk1.top());
                stk1.pop();
            }
        }else{
            while(!stk2.empty()){
                res.push_back(stk2.top());
                stk2.pop();
            }
        }
        return res;
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char, vector<string>> ump;
        ump['2']={"a", "b", "c"};
        ump['3']={"d", "e", "f"};
        ump['4']={"g", "h", "i"};
        ump['5']={"j", "k", "l"};
        ump['6']={"m", "n", "o"};
        ump['7']={"p", "q", "r", "s"};
        ump['8']={"t", "u", "v"};
        ump['9']={"w", "x", "y", "z"};
        vector<string> ans=solve(ump, digits);
        return ans;
    }
};
