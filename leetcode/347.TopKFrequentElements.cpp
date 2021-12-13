/*


Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
 

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.




*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        for(auto i : nums){
            ump[i]++;
        }
        priority_queue<pair<int, int>> pq;
        priority_queue<int, vector<int>, greater<int> > gq;
        for(auto i : ump){
            pair<int, int> p = make_pair(i.second, i.first);
            pq.push(p);
        }
        vector<int> res;
        while(k-- and !pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
        
    }
};
