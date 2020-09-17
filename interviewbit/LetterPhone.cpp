/*

Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



The digit 0 maps to 0 itself.
The digit 1 maps to 1 itself.

Input: Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Make sure the returned strings are lexicographically sorted.

*/


unordered_map<int,string> ump;
    void ini_map(){
        ump[0]="0";
        ump[1]="1";
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

vector<string> Solution::letterCombinations(string digits) {
    
    ini_map();
        vector<string> ans;
        
        if(digits.size()==0){
            return ans;
        }
        /*
        if(digits=="0" or digits=="1"){
            ans.push_back(digits);
            return ans;
        }
        */
        helper(ans,digits,0,digits.size(),"");
        return ans;
}
