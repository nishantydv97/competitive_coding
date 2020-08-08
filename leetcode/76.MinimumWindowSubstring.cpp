/*

Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.


*/


class Solution {
public:
    string minWindow(string s, string t) {
        int hashs[256]={0};
        int hasht[256]={0};
        if(s.length()<t.length())
        {
            return "";
        }
        for(int i=0;i<t.length();i++)
        {
            hasht[t[i]]++;
        }
        int start=0,start_index=-1;
        int minlen=INT_MAX;
        int count=0;
        for(int j=0;j<s.length();j++)
        {
            hashs[s[j]]++;
            if(hasht[s[j]]!=0 && hashs[s[j]]<=hasht[s[j]])
            {
                count++;
            }
            if(count==t.length())
            {
                while(hashs[s[start]]>hasht[s[start]] || hasht[s[start]]==0 )
                {
                    if(hashs[s[start]]>hasht[s[start]])
                    {
                        hashs[s[start]]--;
                    }
                    start++;
                }
                int len=j-start+1;
                if(len<minlen)
                {
                    minlen=len;
                    start_index=start;
                }
            }
        }
        if(start_index==-1)
        {
            return "";
        }
        else
        {
            return s.substr(start_index,minlen);
        }
    }
};
