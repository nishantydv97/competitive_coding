/*

Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

 

Example 1:


Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].
Example 2:


Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
Example 3:

Input: matrix = [[1]]
Output: 1
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 200
0 <= matrix[i][j] <= 231 - 1


*/


class Solution {
public:
    int solve(vector<vector<int>>& mat, int i, int j, vector<vector<int>>& dp){
        int left=0,right=0,up=0,down=0;
        if(dp[i][j]) return dp[i][j];
        if(i>=0 and i<mat.size() and j-1>=0 and j-1<mat[0].size()  and mat[i][j-1]>mat[i][j]){
            left=1+solve(mat, i, j-1, dp);
        }
        if(i>=0 and i<mat.size() and j+1>=0 and j+1<mat[0].size()  and mat[i][j+1]>mat[i][j]){
            right=1+solve(mat, i, j+1, dp);
        }
        if(i-1>=0 and i-1<mat.size() and j>=0 and j<mat[0].size()  and mat[i-1][j]>mat[i][j]){
            up=1+solve(mat, i-1, j, dp);
        }
        if(i+1>=0 and i+1<mat.size() and j>=0 and j<mat[0].size()  and mat[i+1][j]>mat[i][j]){
            down=1+solve(mat, i+1, j, dp);
        }
        return dp[i][j]=max(up, max(down, max(left, right)));
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int res=0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        if(!matrix.size()) return res;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                res=max(res, 1+solve(matrix, i, j, dp));
            }
        }
        
        return res;
    }
};
