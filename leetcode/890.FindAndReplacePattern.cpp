/*

Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.

A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.

 

Example 1:

Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation, since a and b map to the same letter.

Example 2:

Input: words = ["a","b","c"], pattern = "a"
Output: ["a","b","c"]

 

Constraints:

    1 <= pattern.length <= 20
    1 <= words.length <= 50
    words[i].length == pattern.length
    pattern and words[i] are lowercase English letters.





*/

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for(auto i : words){
            unordered_map<char, char> ump1;
            unordered_map<char, char> ump2;
            bool flag=1;
            for(int j=0; j<i.size(); j++){
                if(ump1.find(pattern[j])!=ump1.end() or ump2.find(i[j])!=ump1.end()){
                    if(ump1[pattern[j]]!=i[j] or ump2[i[j]]!=pattern[j]){
                        flag=0;
                        continue;
                    }
                }else{
                    ump1[pattern[j]]=i[j];
                    ump2[i[j]]=pattern[j];
                }
            }
            if(flag) res.push_back(i);
        }
        return res;
    }
};
