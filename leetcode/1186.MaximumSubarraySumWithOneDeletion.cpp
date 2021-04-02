/*

Given an array of integers, return the maximum sum for a non-empty subarray (contiguous elements) with at most one element deletion. In other words, you want to choose a subarray and optionally delete one element from it so that there is still at least one element left and the sum of the remaining elements is maximum possible.

Note that the subarray needs to be non-empty after deleting one element.

 

Example 1:

Input: arr = [1,-2,0,3]
Output: 4
Explanation: Because we can choose [1, -2, 0, 3] and drop -2, thus the subarray [1, 0, 3] becomes the maximum value.
Example 2:

Input: arr = [1,-2,-2,3]
Output: 3
Explanation: We just choose [3] and it's the maximum sum.
Example 3:

Input: arr = [-1,-1,-1,-1]
Output: -1
Explanation: The final subarray needs to be non-empty. You can't choose [-1] and delete -1 from it, then get an empty subarray to make the sum equals to 0.
 

Constraints:

1 <= arr.length <= 105
-104 <= arr[i] <= 104



*/


class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int ans=arr[0];
        int i=0;
        int j=arr.size()-1;
        vector<int> f=arr;
        vector<int> b=arr;
        int fTmp=0;
        int bTmp=0;
        //int bestMax=arr[0];
        while(i<arr.size() and j>=0){
            fTmp+=arr[i];
            bTmp+=arr[j];
            f[i]=max(f[i], fTmp);
            fTmp=f[i];
            b[j]=max(b[j], bTmp);
            bTmp=b[j];
            ans=max(ans, max(f[i], b[j]));
            i++;j--;
        }
        for(auto i : f) cout<<i<<" ";
        cout<<"\n";
        for(auto i : b) cout<<i<<" ";
        cout<<"\n";
        for(int i=1;i<arr.size()-1;i++){
            ans=max(ans, f[i-1]+b[i+1]);
        }
        return ans;
    }
};
