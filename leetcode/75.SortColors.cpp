/*


Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Follow up:

Could you solve this problem without using the library's sort function?
Could you come up with a one-pass algorithm using only O(1) constant space?
 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
Example 3:

Input: nums = [0]
Output: [0]
Example 4:

Input: nums = [1]
Output: [1]


*/



class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero=0;
        int ones=0;
        for(auto i : nums){
            if(i==0){
                zero++;
            }else if(i==1){
                ones++;
            }
        }
        int i=0;
        while(i<nums.size()){
            if(zero){
                nums[i]=0;
                zero--;
                i++;
                continue;
            }
            if(ones){
                ones--;
                nums[i]=1;
                i++;
                continue;
            }else{
                nums[i]=2;
                i++;
                continue;
            }
        }
        
    }
};
