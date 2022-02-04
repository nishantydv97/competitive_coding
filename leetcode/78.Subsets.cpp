/*

Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
Accepted
965,237
Submissions
1,384,221


*/

class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int>& nums, vector<int> tmp, int i, unordered_set<string>& st, string s){
        if(st.find(s)==st.end()){
            res.push_back(tmp);
            st.insert(s);
        }
        if(i>=nums.size()) return; 
        // not select
        helper(nums, tmp, i+1, st, s);
        //select
        tmp.push_back(nums[i]);
        helper(nums, tmp, i+1, st, s+to_string(nums[i])+"|");
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        string s="";
        unordered_set<string> st;
        vector<int> tmp;
        int i=0;
        helper(nums, tmp, i, st, s);
        return res;
    }
};
