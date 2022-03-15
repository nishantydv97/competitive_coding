/*

Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

 

Example 1:


Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.
Example 2:


Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 100
-100 <= matrix[i][j] <= 100
Accepted
115,868
Submissions
172,602


*/

class Solution {
public:
    int mini=INT_MAX;
    void dfs(int curr, int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp) {
        if(i<0 or i>=mat.size() or j<0 or j>=mat[0].size()) return;
        curr+=mat[i][j];
        if(dp[i][j]<=curr) return;
        dp[i][j]=curr;
        //cout<<curr<<endl;
        if(i==mat.size()-1){
            //cout<<curr<<endl;
            mini = min(mini, curr);
            return;
        }
        if(i+1<mat.size()){
            dfs(curr, i+1, j, mat, dp);
        }
        if(j-1>=0 and i+1<mat.size()){
            dfs(curr, i+1, j-1, mat, dp);
        }
        if(i+1<mat.size() and j+1<mat[0].size()){
            dfs(curr, i+1, j+1, mat, dp);
        }
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), INT_MAX));
        for(int i=0; i<matrix[0].size(); i++){
            dfs(0, 0, i, matrix, dp);
        }
        // dfs(0, 0, 2, matrix, dp);
        // cout<<mini<<endl;
        return mini;
    }
};
