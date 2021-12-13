/*

Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100



*/

class Solution {
public:
//     bool helper(int half, int i, vector<int>& nums, int sum){
//         cout<<sum<<endl;
//         //select
//         if(i>=nums.size() or sum>half) return 0;
//         if(sum==half) return 1;
        
//         return helper(half, i+1, nums, sum+nums[i]) || helper(half, i+1, nums, sum);
        
//     }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(), nums.end(), 0);
        //sort(nums.begin(), nums.end());
        if(sum&1) return 0;
        int half=sum/2;
//        return helper(half, 0, nums, 0);
        vector<int> dp(half+1, 0);
        dp[0]=1;
        for(auto i : nums){
            for(int j=half; j>=i; j--){
                if(dp[j-i] || j==i) dp[j]=1;
                //dp[j]=(dp[j-i] or i==j);
            }
        }
        return dp[half];
    }
};
