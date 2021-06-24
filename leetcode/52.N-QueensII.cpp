/*

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.

 

Example 1:

Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.

Example 2:

Input: n = 1
Output: 1

 

Constraints:

    1 <= n <= 9



*/


class Solution {
public:
    bool isSafe(vector<string> &s, int row, int col, int &sz){
        //check if present in same column
        for(int i=row-1; i>=0; i--){
            if(s[i][col]=='Q') return false;
        }
        //check up left
        int i=row-1,j=col-1;
        while(i>=0 and j>=0 and j<sz){
            if(s[i][j]=='Q') return false;
            i--;
            j--;
        }
        //check up right
        i=row-1;j=col+1;
        while(i>=0 and j>=0 and j<sz){
            if(s[i][j]=='Q') return false;
            i--;
            j++;
        }
        return true;
    }
    bool nQueen(vector<string>& sol, int row, int col, int sz, vector<vector<string>>& res){
        if(row>=sz){
            res.push_back(sol);
            return false;
        }
        for(int i=0; i<sz; i++){
            if(isSafe(sol, row, i, sz)){
                sol[row][i]='Q';
                if(nQueen(sol, row+1, col, sz, res))
                    return true;
                sol[row][i]='.';
            }
        }
        return false;
    }
    int totalNQueens(int n) {
        vector<vector<string>> results;
        vector<string> sol(n, string(n,'.'));
        nQueen(sol, 0,0, sol.size(), results);
        return results.size();
        
    }
};
