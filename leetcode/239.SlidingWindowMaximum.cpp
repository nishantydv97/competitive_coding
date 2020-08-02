/*

239. Sliding Window Maximum
Hard
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

Follow up:
Could you solve it in linear time?

Example:

Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7] 
Explanation: 

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
 

Constraints:

1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
1 <= k <= nums.length

*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> v;
        deque<int> dq;
        if(nums.size()<=k){
            v.push_back(*max_element(nums.begin(), nums.end()));
            return v;
        }
        dq.push_back(0);
        /*
        for(auto i : dq){
                cout<<i<<" ";
            }
            cout<<"\n";
            */
        for(int i=1;i<k;i++){
            if(i-dq.front()>k-1){
                dq.pop_front();
            }
            while(!dq.empty()  && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            
            dq.push_back(i);
            //v.push_back(nums[dq.front()]);
            /*
            for(auto i : dq){
                cout<<i<<" ";
            }
            cout<<"\n";
            */
        }
        v.push_back(nums[dq.front()]);
        for(int i=k;i<nums.size();i++){
            if(i-dq.front()>k-1){
                dq.pop_front();
            }
            while(!dq.empty()  && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            
            dq.push_back(i);
            v.push_back(nums[dq.front()]);
            /*
            for(auto i : dq){
                cout<<i<<" ";
            }
            cout<<"\n";
            */
        }
        /*
        for(auto i : dq){
            cout<<i<<" ";
        }
        */
        return v;
    }
};
