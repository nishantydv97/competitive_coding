/*

In an alien language, surprisingly they also use english lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographicaly in this alien language.

 

Example 1:

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
Example 2:

Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.
Example 3:

Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 20
order.length == 26
All characters in words[i] and order are English lowercase letters.


*/


class Solution {
public:
    unordered_map<char, int> ump;
    bool comp(string s1, string s2){
        int l1=s1.size();
        int l2=s2.size();
        int minLen=min(l1, l2);
        for(int i=0; i<minLen; i++){
            if(ump[s1[i]]!=ump[s2[i]]){
                return ump[s1[i]]<ump[s2[i]];
            }
        }
        return l1<=l2;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        if(words.size()<2) return 1;
        for(int i=0;i<order.size();i++){
            ump[order[i]]=i;
        }
        for(int i=1; i<words.size(); i++){
            if(!comp(words[i-1], words[i])) return 0;
        }
        return 1;
    }
};
