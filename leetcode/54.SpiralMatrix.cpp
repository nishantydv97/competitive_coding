/*

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

*/


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        if(matrix.size()==0){
            return v;
        }
        vector<vector<int>> vis(matrix.size(), vector<int> (matrix[0].size(),0));

        int dia=matrix.size()*matrix[0].size();
        int cnt=0;
        char dir_arr[4]={'r','d','l','u'};
        int dir=0;
        int i=0,j=0;
        while(cnt<dia){
            if(dir_arr[dir%4]=='r'){
                while(j<matrix[0].size() && vis[i][j]==0){
                    v.push_back(matrix[i][j]);
                    vis[i][j]=1;
                    j++;
                    cnt++;
                }
                dir++;
                i++;
                j--;
            }else if(dir_arr[dir%4]=='d'){
                //cout<<"i is "<<i<<" j is "<<j<<endl;
                while(i<matrix.size() && vis[i][j]==0){
                    //cout<<"i is "<<i<<endl;
                    v.push_back(matrix[i][j]);
                    vis[i][j]=1;
                    i++;
                    cnt++;
                }
                dir++;
                j--;
                i--;
            }else if(dir_arr[dir%4]=='l' && vis[i][j]==0){
                while(j>=0 && vis[i][j]==0){
                    v.push_back(matrix[i][j]);
                    vis[i][j]=1;
                    j--;
                    cnt++;
                }
                dir++;
                i--;
                j++;
            }else{
                while(i>=0 && vis[i][j]==0){
                    v.push_back(matrix[i][j]);
                    vis[i][j]=1;
                    i--;
                    cnt++;
                }
                dir++;
                j++;
                i++;
            }
        }
        return v;
    }
};
