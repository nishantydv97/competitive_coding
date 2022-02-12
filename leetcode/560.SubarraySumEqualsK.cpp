/*


Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107
Accepted
710,279
Submissions
1,611,140


*/


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        int sum=0;
        unordered_map<int, int> ump;
        ump[0]=1;
        for(auto i : nums){
            sum+=i;
            if(ump.find(sum-k)!=ump.end()){
                count+=ump[sum-k];
            }
            ump[sum]++;
        }
        return count;
    }
};
