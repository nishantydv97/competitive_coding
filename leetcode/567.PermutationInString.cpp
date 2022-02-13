/*

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 

Constraints:

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.
Accepted
334,045
Submissions
740,386


*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);
        for(auto i : s1) v1[i-'a']++;
        for(int i=0; i<s1.size(); i++) v2[s2[i]-'a']++;        
        if(v1==v2) return true;
        int i=0;
        for(int j=s1.size(); j<s2.size(); j++){
            if(v1==v2) return true;
            v2[s2[i++]-'a']--;
            v2[s2[j]-'a']++;
        }
        if(v1==v2) return true;
        return false;
    }
};
