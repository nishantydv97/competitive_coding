/*


You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.

 

Example 1:

Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
Example 2:

Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
Example 3:

Input: words = ["abcd","dbqca"]
Output: 1
Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.
 

Constraints:

1 <= words.length <= 1000
1 <= words[i].length <= 16
words[i] only consists of lowercase English letters.
Accepted
175,300
Submissions
304,952


*/

class Solution {
public:
    
    int helper(unordered_set<string>& wordSet, string word, unordered_map<string, int>& dp){
        if(wordSet.find(word)==wordSet.end()) return 0;
        if(dp[word]) return dp[word];
        int k=1;
        for(int i=0; i<word.size(); i++){
            string tmp=word;
            tmp.erase(i, 1);
            int l=helper(wordSet, tmp, dp);
            k=max(k, l==0 ? 0 : 1+l);
        }
        return dp[word]=k;
    }
    int longestStrChain(vector<string>& words) {
        unordered_set<string> wordSet;
        int result=1;
        for(auto word : words){
            wordSet.insert(word);
        }
        unordered_map<string, int> dp;
        for(auto i : wordSet){
            result=max(result, helper(wordSet, i, dp));
        }
        return result;
    }
};
