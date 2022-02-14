/*

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and space is marked as 1 and 0 respectively in the grid.

 

Example 1:


Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
Example 2:


Input: obstacleGrid = [[0,1],[0,0]]
Output: 1
 

Constraints:

m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] is 0 or 1.


*/


class Solution {
public:
    bool validIandJ(int i, int j, vector<vector<int>>& grid){
        if(i<0 or i<0 or i>=grid.size() or j>=grid[0].size()) return 0;
        return 1;
    }
    int helper(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j, vector<vector<int>>& dp){
        //cout<<i<<" "<<j<<endl;
        if(!validIandJ(i,j, grid)) return 0;
        if(i==grid.size()-1 and j==grid[0].size()-1 and !grid[i][j]) return 1;
        int r=0,d=0;
        //right
        if(validIandJ(i, j+1, grid) and !grid[i][j+1] and !vis[i][j+1]){
            vis[i][j+1]=1;
            r=dp[i][j+1] ? dp[i][j+1] : helper(grid, vis, i, j+1, dp);
        }
        //down
        if(validIandJ(i+1, j, grid) and !vis[i+1][j] and !grid[i+1][j]){
            vis[i+1][j]=1;
            d=dp[i+1][j] ? dp[i+1][j] : helper(grid, vis, i+1, j, dp);
        }
        
        if(validIandJ(i, j+1, grid)) vis[i][j+1]=0;
        if(validIandJ(i+1, j, grid)) vis[i+1][j]=0;
        return dp[i][j]=r+d;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        if(grid.size()==0) return 0;
        if(grid[0][0]) return 0;
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
        return helper(grid, vis, 0, 0, dp);
    }
};
