/*

Given a list of non-negative integers nums, arrange them such that they form the largest number.

Note: The result may be very large, so you need to return a string instead of an integer.

 

Example 1:

Input: nums = [10,2]
Output: "210"
Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"
Example 3:

Input: nums = [1]
Output: "1"
Example 4:

Input: nums = [10]
Output: "10"
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 109



*/



class Solution {
public:
    bool static sorti(int x, int y){
        return to_string(y)+to_string(x)<to_string(x)+to_string(y);
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), sorti);
        string ans="";
        int i=0;
        while(nums[i]==0 and i<nums.size()-1) i++;
        while(i<nums.size()){
            ans+=to_string(nums[i]);
            i++;
        }
        return ans;
    }
};
