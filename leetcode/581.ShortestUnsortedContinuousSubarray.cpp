/*
Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

Return the shortest such subarray and output its length.

 

Example 1:

Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Example 2:

Input: nums = [1,2,3,4]
Output: 0
Example 3:

Input: nums = [1]
Output: 0
 

Constraints:

1 <= nums.length <= 104
-105 <= nums[i] <= 105
 

Follow up: Can you solve it in O(n) time complexity?




*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int> mini(n, 0);
        vector<int> maxi(n, 0);
        int maxVar=nums[0];
        for(int i=0;i<n;i++){
            maxVar=max(maxVar, nums[i]);
            maxi[i]=maxVar;
        }
        int minVar=nums[n-1];
        for(int i=n-1;i>=0;i--){
            minVar=min(minVar, nums[i]);
            mini[i]=minVar;
        }
        int i=0;
        while(i<n and mini[i]>=maxi[i])i++;
        int start=i;
        i=n-1;
        while(i>=0 and maxi[i]<=mini[i])i--;
        int end=i;
        if(end<=start) return 0;
        return end-start+1;
    }
};
