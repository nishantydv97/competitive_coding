/*


Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

 

Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
Example 2:

Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
Accepted
241,815
Submissions
527,320


*/


class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        vector<int> sum(nums.size(), 0);
        sum[0] = nums[0] ? 1 : -1;
        int ans=0;
        for(int i=1; i<nums.size(); i++){
            sum[i] = (sum[i-1] + (nums[i] ? 1 : -1));
            if(!sum[i]){
                ans=max(ans, i+1);
            }
        }
        unordered_map<int, vector<int>> ump;
        for(int i=0; i<sum.size(); i++){
            ump[sum[i]].push_back(i);
        }
        
        for(auto i : ump){
            ans=max(ans, i.second[i.second.size()-1]-i.second[0]);
        }
        
        return ans;
    }
};
