/*


Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.
Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Input words contain only lowercase letters.
Follow up:
Try to solve it in O(n log k) time and O(n) extra space.



*/



class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> v;
        map<string, int> mp;
        for(auto i : words){
            mp[i]++;
        }
        priority_queue<pair<int, string>> pq;
        for(auto i : mp){
            pq.push(make_pair(i.second, i.first));
        }
        map<int, set<string> , greater <int>> mps;
        
        while(!pq.empty()){
            mps[pq.top().first].insert(pq.top().second);
            pq.pop();
        }
        for(auto i : mps){
            for(auto j : i.second){
                if(k>0){
                    v.push_back(j);
                    k--;
                }else{
                    break;
                }
            }
        }
        return v;
    }
};
