/*

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.


*/


class Solution {
public:
    unordered_map<int,string> ump;
    void ini_map(){
        ump[1]="";
        ump[2]="abc";
        ump[3]="def";
        ump[4]="ghi";
        ump[5]="jkl";
        ump[6]="mno";
        ump[7]="pqrs";
        ump[8]="tuv";
        ump[9]="wxyz";
    }
    
    void helper(vector<string>& ans, string& digits, int start, int end, string prefix){
        //cout<<prefix<<endl;
        if(start==end){
            ans.push_back(prefix);
            return;
        }else{
            for(auto i : ump[(int)(digits[start]-'0')]){
                helper(ans,digits,start+1,end,prefix+i);
                //cout<<i<<" ";
            }
        }
    }
    

    vector<string> letterCombinations(string digits) {
        
        ini_map();
        vector<string> ans;
        if(digits.size()==0){
            return ans;
        }
        helper(ans,digits,0,digits.size(),"");
        return ans;
    }
};
