/*


Given N x M character matrix A of O's and X's, where O = white, X = black.

Return the number of black shapes. A black shape consists of one or more adjacent X's (diagonals not included)



Input Format:

    The First and only argument is a N x M character matrix.
Output Format:

    Return a single integer denoting number of black shapes.
Constraints:

    1 <= N,M <= 1000
    A[i][j] = 'X' or 'O'
Example:

Input 1:
    A = [ OOOXOOO
          OOXXOXO
          OXOOOXO  ]
Output 1:
    3
Explanation:
    3 shapes are  :
    (i)    X
         X X
    (ii)
          X
    (iii)
          X
          X
Note: we are looking for connected shapes here.

XXX
XXX
XXX
is just one single connected black shape.


*/


void dfs(vector<vector<bool>> &vis, vector<string> &A, int i, int j){
    
    if(i>=0 and i<A.size() and j-1>=0 and j-1<A[0].size() and vis[i][j-1]==false and A[i][j-1]=='X'){
        vis[i][j-1]=true;
        dfs(vis,A,i,j-1);
    }
    //right
    if(i>=0 and i<A.size() and j+1>=0 and j+1<A[0].size() and vis[i][j+1]==false and A[i][j+1]=='X'){
        vis[i][j+1]=true;
        dfs(vis,A,i,j+1);
    
    }
    //down
    if(i+1>=0 and i+1<A.size() and j>=0 and j<A[0].size() and vis[i+1][j]==false and A[i+1][j]=='X'){
        vis[i+1][j]=true;
        dfs(vis,A,i+1,j);
    
    }
    //up
    if(i-1>=0 and i-1<A.size() and j>=0 and j<A[0].size() and vis[i-1][j]==false and A[i-1][j]=='X'){
        vis[i-1][j]=true;
        dfs(vis,A,i-1,j);
    }
}


int Solution::black(vector<string> &A) {
    vector<vector<bool>> vis(A.size(), vector<bool>(A[0].size(),0));
    int ans=0;
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[0].size();j++){
            if(A[i][j]=='X' and vis[i][j]==false){
                ans+=1;
                vis[i][j]=true;
                dfs(vis,A,i,j);
            }
        }
    }
    
    return ans;
}



