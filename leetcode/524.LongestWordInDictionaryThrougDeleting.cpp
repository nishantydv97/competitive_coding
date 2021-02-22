/*


Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. 
If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

Example 1:
Input:
s = "abpcplea", d = ["ale","apple","monkey","plea"]

Output: 
"apple"
Example 2:
Input:
s = "abpcplea", d = ["a","b","c"]

Output: 
"a"
Note:
All the strings in the input will only contain lower-case letters.
The size of the dictionary won't exceed 1,000.
The length of all the strings in the input won't exceed 1,000.


*/


class Solution {
public:
    string findLongestWord(string S, vector<string>& d) {
        int maxLen=INT_MIN;
        string ans="";
        for(auto s : d){
            int i=0;
            int j=0;
            while(i<S.size() and j<s.size()){
                if(S[i]==s[j]){
                    j++;
                }
                i++;
            }
            if(j==s.size()){
                if(j>maxLen){
                    maxLen=s.size();
                    ans=s;
                }
                if(j==maxLen){
                    ans=min(ans, s);
                }
            }
        }
        return ans;
    }
};


