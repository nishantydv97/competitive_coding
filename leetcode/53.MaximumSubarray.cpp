/*


Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2:

Input: nums = [1]
Output: 1
Example 3:

Input: nums = [0]
Output: 0
Example 4:

Input: nums = [-1]
Output: -1
Example 5:

Input: nums = [-100000]
Output: -100000
 

Constraints:

1 <= nums.length <= 3 * 104
-105 <= nums[i] <= 105
 

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.



*/


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN;
        int flag=0;
        int tmp=0;
        int maxi=INT_MIN;
        for(auto i : nums){
            if(i>0) flag=1;
            maxi=max(maxi, i);
            tmp+=i;
            if(tmp<0) tmp=0;
            ans=max(ans,tmp);
        }
        if(!flag) return maxi;
        return ans;
    }
};
