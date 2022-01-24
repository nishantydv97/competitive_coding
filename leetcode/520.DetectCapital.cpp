/*

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Given a string word, return true if the usage of capitals in it is right.

 

Example 1:

Input: word = "USA"
Output: true
Example 2:

Input: word = "FlaG"
Output: false
 

Constraints:

1 <= word.length <= 100
word consists of lowercase and uppercase English letters.
Accepted
246,229
Submissions
443,052

*/


class Solution {
public:
    bool detectCapitalUse(string word) {
        int cap=0;
        for(int i=0; i<word.size(); i++){
            if(word[i]<=90 and word[i]>=65){
                cap++;
            }
        }
        if(cap==0) return true;
        if(cap==1 and word[0]<=90 and word[0]>=65) return true;
        if(cap==word.size()) return true;
        return false;
        
    }
};
