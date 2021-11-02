/*

You are given an m x n integer array grid where grid[i][j] could be:

1 representing the starting square. There is exactly one starting square.
2 representing the ending square. There is exactly one ending square.
0 representing empty squares we can walk over.
-1 representing obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

 

Example 1:


Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
Example 2:


Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
Output: 4
Explanation: We have the following four paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
Example 3:


Input: grid = [[0,1],[2,0]]
Output: 0
Explanation: There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.


*/


class Solution {
public:
    void solver(vector<vector<int>>& grid, vector<vector<int>>& visit, int& pathCnt, int currCnt, int i, int j, int& ans){
        if(currCnt==pathCnt and grid[i][j]==2){
            ans++;
            return;
        }
        visit[i][j]=1;
        //left
        if(i<0 or i>=grid.size() or j<0 or j>=grid[0].size()) return;
        if(j-1>=0 and !visit[i][j-1] and grid[i][j-1]!=-1){
             solver(grid, visit, pathCnt, currCnt+1, i, j-1, ans);
        }
        //right
        if(j+1<grid[0].size() and !visit[i][j+1] and grid[i][j+1]!=-1){
            solver(grid, visit, pathCnt, currCnt+1, i, j+1, ans);
        }
        //bottom
        if(i+1<grid.size() and !visit[i+1][j] and grid[i+1][j]!=-1){
            solver(grid, visit, pathCnt, currCnt+1, i+1, j, ans);
        }
        //up
        if(i-1>=0 and !visit[i-1][j] and grid[i-1][j]!=-1){
            solver(grid, visit, pathCnt, currCnt+1, i-1, j, ans);
        }
        visit[i][j]=0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        vector<vector<int>> visit(grid.size(), vector<int>(grid[0].size(), 0));
        pair<int, int> start;
        int cnt=0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==-1) cnt++;
                if(grid[i][j]==1){
                    start=make_pair(i, j);
                }
            }
        }
        int pathCnt=grid.size()*grid[0].size();
        int k=pathCnt-cnt-1;
        int ans=0;
        int currCnt=0;
        solver(grid, visit, k, currCnt, start.first, start.second, ans);
        return ans;
    }
};
