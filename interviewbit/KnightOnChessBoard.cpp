/*

Given any source point, (C, D) and destination point, (E, F) on a chess board, we need to find whether Knight can move to the destination or not.

Knight's movements on a chess board

The above figure details the movements for a knight ( 8 possibilities ).

If yes, then what would be the minimum number of steps for the knight to move to the said point.
If knight can not move from the source point to the destination point, then return -1.

Note: A knight cannot go out of the board.



Input Format:

The first argument of input contains an integer A.
The second argument of input contains an integer B.
    => The chessboard is of size A x B.
The third argument of input contains an integer C.
The fourth argument of input contains an integer D.
    => The Knight is initially at position (C, D).
The fifth argument of input contains an integer E.
The sixth argument of input contains an integer F.
    => The Knight wants to reach position (E, F).
Output Format:

If it is possible to reach the destination point, return the minimum number of moves.
Else return -1.
Constraints:

1 <= A, B <= 500
Example

Input 1:
    A = 8
    B = 8
    C = 1
    D = 1
    E = 8
    F = 8
    
Output 1:
    6

Explanation 1:
    The size of the chessboard is 8x8, the knight is initially at (1, 1) and the knight wants to reach position (8, 8).
    The minimum number of moves required for this is 6.




*/




int Solution::knight(int A, int B, int C, int D, int E, int F) {
    int row=A, col=B, x1=C-1, y1=D-1, x2=E-1, y2=F-1;
    vector<vector<int>> vis(row, vector<int>(col, 0));
    /*
    for(auto i : vis){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    */
    //cout<<"target is "<<x2<<" "<<y2<<endl;
    stack<pair<int, int>> stk1;
    stack<pair<int, int>> stk2;
    if(x1==x2 and y1==y2) return 0;
    int cnt=0;
    stk1.push(make_pair(x1, y1));
    while(!stk1.empty() or !stk2.empty()){
        /*
        for(auto i : vis){
            for(auto j : i){
                cout<<j<<" ";
            }
            cout<<"\n";
        }
        */
        if(!stk1.empty()){
            while(!stk1.empty()){
                pair<int, int> p1=stk1.top();
                if(p1.first==x2 and p1.second==y2) return cnt;
                int i=p1.first;
                int j=p1.second;
                //cout<<i<<" "<<j<<endl;
                stk1.pop();
                //i-2, j+1
                if(i-2>=0 and i-2<row and j+1>=0 and j+1<col and !vis[i-2][j+1]){
                    stk2.push(make_pair(i-2, j+1));
                    vis[i-2][j+1]=1;
                }
                //i-1, j+2
                if(i-1>=0 and i-1<row and j+2>=0 and j+2<col and !vis[i-1][j+2]){
                    stk2.push(make_pair(i-1, j+2));
                    vis[i-1][j+2]=1;
                }
                //i+1, j+2
                if(i+1>=0 and i+1<row and j+2>=0 and j+2<col and !vis[i+1][j+2]){
                    stk2.push(make_pair(i+1, j+2));
                    vis[i+1][j+2]=1;
                }
                //i+2, j+1
                if(i+2>=0 and i+2<row and j+1>=0 and j+1<col and !vis[i+2][j+1]){
                    stk2.push(make_pair(i+2, j+1));
                    vis[i+2][j+1]=1;
                }
                //i+2, j-1
                if(i+2>=0 and i+2<row and j-1>=0 and j-1<col and !vis[i+2][j-1]){
                    stk2.push(make_pair(i+2, j-1));
                    vis[i+2][j-1]=1;
                }
                //i+1, j-2
                if(i+1>=0 and i+1<row and j-2>=0 and j-2<col and !vis[i+1][j-2]){
                    stk2.push(make_pair(i+1, j-2));
                    vis[i+1][j-2]=1;
                }
                //i-1, j-2
                if(i-1>=0 and i-1<row and j-2>=0 and j-2<col and !vis[i-1][j-2]){
                    stk2.push(make_pair(i-1, j-2));
                    vis[i-1][j-2]=1;
                }
                //i-2, j-1
                if(i-2>=0 and i-2<row and j-1>=0 and j-1<col and !vis[i-2][j-1]){
                    stk2.push(make_pair(i-2, j-1));
                    vis[i-2][j-1]=1;
                }
                
            }
            cnt++;
        }else{
            while(!stk2.empty()){
                pair<int, int> p1=stk2.top();
                if(p1.first==x2 and p1.second==y2) return cnt;
                int i=p1.first;
                int j=p1.second;
                //cout<<i<<" "<<j<<endl;
                stk2.pop();
                //i-2, j+1
                if(i-2>=0 and i-2<row and j+1>=0 and j+1<col and !vis[i-2][j+1]){
                    stk1.push(make_pair(i-2, j+1));
                    vis[i-2][j+1]=1;
                }
                //i-1, j+2
                if(i-1>=0 and i-1<row and j+2>=0 and j+2<col and !vis[i-1][j+2]){
                    stk1.push(make_pair(i-1, j+2));
                    vis[i-1][j+2]=1;
                }
                //i+1, j+2
                if(i+1>=0 and i+1<row and j+2>=0 and j+2<col and !vis[i+1][j+2]){
                    stk1.push(make_pair(i+1, j+2));
                    vis[i+1][j+2]=1;
                }
                //i+2, j+1
                if(i+2>=0 and i+2<row and j+1>=0 and j+1<col and !vis[i+2][j+1]){
                    stk1.push(make_pair(i+2, j+1));
                    vis[i+2][j+1]=1;
                }
                //i+2, j-1
                if(i+2>=0 and i+2<row and j-1>=0 and j-1<col and !vis[i+2][j-1]){
                    stk1.push(make_pair(i+2, j-1));
                    vis[i+2][j-1]=1;
                }
                //i+1, j-2
                if(i+1>=0 and i+1<row and j-2>=0 and j-2<col and !vis[i+1][j-2]){
                    stk1.push(make_pair(i+1, j-2));
                    vis[i+1][j-2]=1;
                }
                //i-1, j-2
                if(i-1>=0 and i-1<row and j-2>=0 and j-2<col and !vis[i-1][j-2]){
                    stk1.push(make_pair(i-1, j-2));
                    vis[i-1][j-2]=1;
                }
                //i-2, j-1
                if(i-2>=0 and i-2<row and j-1>=0 and j-1<col and !vis[i-2][j-1]){
                    stk1.push(make_pair(i-2, j-1));
                    vis[i-2][j-1]=1;
                }
                
            }
            cnt++;
        }
    }
    return -1;
}
