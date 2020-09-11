/*

Given an array of integers nums and an integer k. A subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

 

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There is no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16
 

Constraints:

1 <= nums.length <= 50000
1 <= nums[i] <= 10^5
1 <= k <= nums.length


*/
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&1){
                v.push_back(i);
            }
        }
        int i=0;
        int j=k-1;
        int sum=0;
        while(j<v.size()){
            int low,hight;
            if(i==0){
                low=v[i]+1;
                if(j==v.size()-1){
                    hight=nums.size()-v[j];
                }else{
                    hight=v[j+1]-v[j];
                }
                
            }else{
                low=v[i]-v[i-1];
                if(j==v.size()-1){
                    hight=nums.size()-v[j];
                }else{
                    hight=v[j+1]-v[j];
                }
            }
            sum+=(hight*low);
            j++;
            i++;
        }
        return sum;
        
    }
};
