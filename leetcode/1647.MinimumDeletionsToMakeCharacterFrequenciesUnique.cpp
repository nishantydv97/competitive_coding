/*

A string s is called good if there are no two different characters in s that have the same frequency.

Given a string s, return the minimum number of characters you need to delete to make s good.

The frequency of a character in a string is the number of times it appears in the string. For example, in the string "aab", the frequency of 'a' is 2, while the frequency of 'b' is 1.

 

Example 1:

Input: s = "aab"
Output: 0
Explanation: s is already good.
Example 2:

Input: s = "aaabbbcc"
Output: 2
Explanation: You can delete two 'b's resulting in the good string "aaabcc".
Another way it to delete one 'b' and one 'c' resulting in the good string "aaabbc".
Example 3:

Input: s = "ceabaacb"
Output: 2
Explanation: You can delete both 'c's resulting in the good string "eabaab".
Note that we only care about characters that are still in the string at the end (i.e. frequency of 0 is ignored).
 

Constraints:

1 <= s.length <= 105
s contains only lowercase English letters.


*/



class Solution {
public:
    void printVector(vector<int> vec){
        for(auto i : vec){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    bool static comp(int i, int j){
        return i>j;
    }
    int minDeletions(string s) {
        unordered_map<int, int> ump;
        for(auto i : s){
            ump[i]++;
        }
        vector<int> freq;
        for(auto i : ump){
            freq.push_back(i.second);
        }
        sort(freq.begin(),freq.end(), comp);
        //printVector(freq);
        int del=0;
        int i=1;
        if(freq.size()==0 or freq.size()==1){
            return del;
        }else{
            while(i<freq.size()){
                if(freq[i-1]==0){
                    while(i<freq.size()){
                        del+=freq[i];
                        i++;
                    }
                    break;
                }
                if(freq[i-1]<=freq[i]){
                    del+=(abs(freq[i-1]-freq[i])+1);
                    freq[i]=freq[i-1]-1;
                }
                i++;
                //printVector(freq);
            }
        }
        return del;
    }
};
