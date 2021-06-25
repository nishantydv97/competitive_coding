/*

There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.

Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.

 

Example 1:

Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
Output: 6

Example 2:

Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
Output: 12

 

Constraints:

    1 <= m, n <= 50
    0 <= maxMove <= 50
    0 <= startRow < m
    0 <= startColumn < n

Accepted
53,010
Submissions
134,848


*/


class Solution {
    public:
    int mod=1e9+7;
    int solve(int m, int n, int maxMove, int curMove, int startRow, int startColumn, vector<vector<vector<int>>>& dp){
        if(((startRow<0) or (startRow>=m) or (startColumn<0) or (startColumn>=n)))
            return 1;
        if(curMove>=maxMove)
            return 0;
        if(dp[startRow][startColumn][curMove]!=-1) return dp[startRow][startColumn][curMove];
        int x1=solve(m,n, maxMove, curMove+1, startRow+1, startColumn, dp);
        int x2=solve(m,n, maxMove, curMove+1, startRow-1, startColumn, dp);
        int x3=solve(m,n, maxMove, curMove+1, startRow, startColumn+1, dp);
        int x4=solve(m,n, maxMove, curMove+1, startRow, startColumn-1, dp);
        return dp[startRow][startColumn][curMove]=(x1+(x2+(x3+x4)%mod)%mod)%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>> dp1(m, vector<int>(n, -1));
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove, -1)));
        return solve(m, n, maxMove, 0, startRow, startColumn, dp);
    }
};
