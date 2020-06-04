/*

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

*/


class Solution {
public:
    int trap(vector<int>& height) {
        int max1[height.size()];
        int max2[height.size()];
        int maxi=INT_MIN;
        for(int i=0;i<height.size();i++){
            if(height[i]>maxi){
                max1[i]=height[i];
                maxi=height[i];
            }else{
                max1[i]=maxi;
            }
        }
        maxi=INT_MIN;
        for(int i=height.size()-1;i>=0;i--){
            if(height[i]>maxi){
                max2[i]=height[i];
                maxi=height[i];
            }else{
                max2[i]=maxi;
            }
        }
        int ans=0;
        for(int i=0;i<height.size();i++){
            ans+=(min(max1[i],max2[i])-height[i]);
        }
        return ans;
    }
};
