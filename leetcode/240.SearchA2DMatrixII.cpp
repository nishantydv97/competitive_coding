/*

Write an efficient algorithm that searches for a target value in an m x n integer matrix. The matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
 

Example 1:


Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true
Example 2:


Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= n, m <= 300
-109 <= matix[i][j] <= 109
All the integers in each row are sorted in ascending order.
All the integers in each column are sorted in ascending order.
-109 <= target <= 109


*/



class Solution {
public:
    bool binarySearch(vector<int> &v, vector<vector<int>>& matrix, int start, int end, int target, bool &flag){
        //cout<<"start is "<<start<<" end is "<<end<<endl;
        if(start<=end){
            int mid=start+((end-start)/2);
            //cout<<"mid is "<<mid<<endl;
            if(v[mid]<=target){
                if(binary_search(matrix[mid].begin(), matrix[mid].end(), target)){
                    //cout<<"found the ans"<<endl;
                    flag=1;
                    return 1;
                }else{
                    binarySearch(v, matrix, start, mid-1, target, flag);
                    binarySearch(v, matrix, mid+1, end , target, flag);

                }
            }else{
                binarySearch(v, matrix, start, mid-1, target, flag);
            }
            //return 0;
        }
        //cout<<"reached at the end";
        return 0;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> v;
        for(int i=0;i<matrix.size(); i++){
            v.push_back(matrix[i][0]);
        }
        bool flag=0;
        binarySearch(v, matrix, 0, matrix.size()-1, target, flag);
        return flag;
    }
};
