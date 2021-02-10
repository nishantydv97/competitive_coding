/*

We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.

Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.

A subsequence of array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: nums = [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].
Example 2:

Input: nums = [1,2,3,4]
Output: 2
Example 3:

Input: nums = [1,1,1,1]
Output: 0


*/


class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> ump;
        for(auto i : nums){
            ump[i]++;
        }
        queue<pair<int, int>> pq;
        for(auto i : ump){
            pq.push(make_pair(i.second, i.first));
        }
        int ans=0;
        while(!pq.empty()){   
            ans=max(ans, max(pq.front().first+ump[pq.front().second-1]==pq.front().first ? 0 : pq.front().first+ump[pq.front().second-1], pq.front().first+ump[pq.front().second+1]==pq.front().first ? 0 : pq.front().first+ump[pq.front().second+1]));
            pq.pop();
        }
        return ans;
    }
};
