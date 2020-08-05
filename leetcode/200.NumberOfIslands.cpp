/*

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]

*/



class Solution {
public:
    void dfs(vector<vector<char>>& v, vector<vector<char>>& vis, int i, int j){
        //cout<<i<<" "<<j<<endl;
        if(i>=0  && i<v.size() && j>=0 && j<v[0].size()){
            vis[i][j]='1';
        }
        //cout<<"hola"<<endl;
        //up
        if(i-1>=0 && i-1<v.size() && v[i-1][j]=='1' && vis[i-1][j]=='0'){
            dfs(v,vis,i-1,j);
        }
        //down
        if(i+1<vis.size() && i+1>=0 && v[i+1][j]=='1' && vis[i+1][j]=='0'){
            dfs(v,vis,i+1,j);
        }
        //right
        if(j+1<v[0].size() && j>=0 && v[i][j+1]=='1' && vis[i][j+1]=='0'){
            dfs(v,vis,i,j+1);
        }
        //left
        if(j-1>=0 && j<=v[0].size() && v[i][j-1]=='1' && vis[i][j-1]=='0'){
            dfs(v,vis,i,j-1);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0){
            return 0;
        }
        vector<vector<char>> vis(grid.size(), vector<char>(grid[0].size(),'0'));
        /*
        for(auto i : vis){
            for(auto j : i){
                cout<<j<<" ";
            }
            cout<<"\n";
        }
        */
        //dfs(grid,vis,0,0);
        /*
        for(auto i : vis){
            for(auto j : i){
                cout<<j<<" ";
            }
            cout<<"\n";
        }
        */
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1' && vis[i][j]=='0'){
                    cout<<i<<" "<<j<<endl;
                    dfs(grid,vis,i,j);
                    //cout<<"ans is "<<ans<<endl;
                    ans++;
                }
            }
        }
        
        return ans;
    }
};
