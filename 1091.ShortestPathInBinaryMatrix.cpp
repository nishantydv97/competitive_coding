/*

In an N by N square grid, each cell is either empty (0) or blocked (1).

A clear path from top-left to bottom-right has length k if and only if it is composed of cells C_1, C_2, ..., C_k such that:

Adjacent cells C_i and C_{i+1} are connected 8-directionally (ie., they are different and share an edge or corner)
C_1 is at location (0, 0) (ie. has value grid[0][0])
C_k is at location (N-1, N-1) (ie. has value grid[N-1][N-1])
If C_i is located at (r, c), then grid[r][c] is empty (ie. grid[r][c] == 0).
Return the length of the shortest such clear path from top-left to bottom-right.  If such a path does not exist, return -1.

 

Example 1:

Input: [[0,1],[1,0]]


Output: 2

Example 2:

Input: [[0,0,0],[1,1,0],[1,1,0]]


Output: 4

 

Note:

1 <= grid.length == grid[0].length <= 100
grid[r][c] is 0 or 1


Problem link : https://leetcode.com/problems/shortest-path-in-binary-matrix/



*/


class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int dis=INT_MAX;
        int n=grid[0].size();
        if(grid[0][0]!=0 or grid[n-1][n-1]!=0) return -1;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        if(n<=1) return 1;
        queue<pair<int, int>> q;
        int i=0,j=0;
        q.push(make_pair(i,j));
        while(!q.empty()){
            i=q.front().first;
            j=q.front().second;
            if(i==n-1 and j==n-1){
                cout<<i<<" "<<j<<endl;
                dis=min(dis, vis[i][j]);
            }
            //top
            if(i-1<n and i-1>=0 and j>=0 and j<n and !vis[i-1][j] and !grid[i-1][j]){
                q.push(make_pair(i-1,j));
                vis[i-1][j]=vis[i][j]+1;
            }
            //top right
            if(i-1<n and i-1>=0 and j+1>=0 and j+1<n and !vis[i-1][j+1] and !grid[i-1][j+1]){
                q.push(make_pair(i-1,j+1));
                vis[i-1][j+1]=vis[i][j]+1;
            }
            //right
            if(i<n and i>=0 and j+1>=0 and j+1<n and !vis[i][j+1] and !grid[i][j+1]){
                q.push(make_pair(i,j+1));
                vis[i][j+1]=vis[i][j]+1;
            } 
            //bottom right
            if(i+1<n and i+1>=0 and j+1>=0 and j+1<n and !vis[i+1][j+1] and !grid[i+1][j+1]){
                q.push(make_pair(i+1,j+1));
                vis[i+1][j+1]=vis[i][j]+1;
            }
            //bottom
            if(i+1<n and i+1>=0 and j>=0 and j<n and !vis[i+1][j] and !grid[i+1][j]){
                q.push(make_pair(i+1,j));
                vis[i+1][j]=vis[i][j]+1;
            }
            //bottom left
            if(i+1<n and i+1>=0 and j-1>=0 and j-1<n and !vis[i+1][j-1] and !grid[i+1][j-1]){
                q.push(make_pair(i+1,j-1));
                vis[i+1][j-1]=vis[i][j]+1;
            }
            //left
            if(i<n and i>=0 and j-1>=0 and j-1<n and !vis[i][j-1] and !grid[i][j-1]){
                q.push(make_pair(i,j));
                vis[i][j-1]=vis[i][j]+1;
            }
            //up left
            if(i-1<n and i-1>=0 and j-1>=0 and j-1<n and !vis[i-1][j-1] and !grid[i-1][j-1]){
                q.push(make_pair(i,j));
                vis[i-1][j-1]=vis[i][j]+1;
            }
            q.pop();
        }
        cout<<"dis is "<<dis<<endl;
        if(dis<INT_MAX) return dis+1;
        return -1;
    }
};
