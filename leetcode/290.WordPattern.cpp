/*

Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

 

Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Example 2:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false
 

Constraints:

1 <= pattern.length <= 300
pattern contains only lower-case English letters.
1 <= s.length <= 3000
s contains only lowercase English letters and spaces ' '.
s does not contain any leading or trailing spaces.
All the words in s are separated by a single space.

*/


class Solution {
public:
    
    vector<string> split (string s, string delimiter) {
        size_t pos_start = 0, pos_end, delim_len = delimiter.length();
        string token;
        vector<string> res;

        while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
            token = s.substr (pos_start, pos_end - pos_start);
            pos_start = pos_end + delim_len;
            res.push_back (token);
        }

        res.push_back (s.substr (pos_start));
        return res;
    }

    
    bool wordPattern(string pattern, string si) {
        vector<string> s=split(si, " ");
        unordered_map<char, string> ump;
        unordered_map<string, char> ump1;
        if(pattern.size()!=s.size()) return 0;
        for(int i=0; i<s.size(); i++){
            if(ump.find(pattern[i])!=ump.end() or ump1.find(s[i])!=ump1.end()){
                if(ump1[s[i]]!=pattern[i]) return 0;
                if(ump[pattern[i]]!=s[i]) return 0;
            }else{
                
                ump[pattern[i]]=s[i];
                ump1[s[i]]=pattern[i];
            }
        }
        return 1;
    }
};
