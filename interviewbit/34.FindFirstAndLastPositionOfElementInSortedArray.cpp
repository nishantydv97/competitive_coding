/*


Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

Follow up: Could you write an algorithm with O(log n) runtime complexity?

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]


*/


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> ans;
        if(nums.size()==0){
            return {-1,-1};
        }
        auto a=lower_bound(nums.begin(),nums.end(),target);
        if(!binary_search(nums.begin(),nums.end(),target)){
            return {-1,-1};
        }
        auto b=upper_bound(nums.begin(),nums.end(),target);
        ans.push_back(a-nums.begin());
        ans.push_back(b-nums.begin()-1);
        return ans;
    }
};
