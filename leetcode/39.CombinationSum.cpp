/*

Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []
 

Constraints:

1 <= candidates.length <= 30
1 <= candidates[i] <= 200
All elements of candidates are distinct.
1 <= target <= 500
Accepted
987,345
Submissions
1,533,176



*/


class Solution {
public:
    vector<vector<int>> res;
    
    void helper(vector<int>& candidates, int target, int curr, vector<int> vec, int i){
        if(curr>target) return;
        if(curr==target){
            res.push_back(vec);
            return;
        }
        for(int j=i; j<candidates.size(); j++){
            vec.push_back(candidates[j]);
            helper(candidates, target, curr+candidates[j], vec, j);
            vec.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> vec;
        helper(candidates, target, 0, vec, 0);
        return res;
    }
};
