/*

Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3
Example 2:

Input: [3,4,-1,1]
Output: 2
Example 3:

Input: [7,8,9,11,12]
Output: 1
Follow up:

Your algorithm should run in O(n) time and uses constant extra space.



*/


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size()==0) return 1;
        if(nums.size()==1){
            if(nums[0]==1) return 2;
            return 1;
            
        }
        for(int i=0;i<nums.size();i++){
            while(nums[i]<nums.size() && nums[i]>=0 && nums[i]!=nums[nums[i]] && nums[i]!=i){
                swap(nums[i],nums[nums[i]]);
            }
        }
        
        int i=1;
        for(;i<nums.size();i++){
            if(nums[i]!=i){
                return i;
            }
        }
        if(i==nums[0]) return i+1;
        return i;
    }
};
