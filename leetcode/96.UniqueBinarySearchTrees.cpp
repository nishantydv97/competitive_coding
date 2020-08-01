/*

Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
 

Constraints:

1 <= n <= 19

*/

class Solution {
public:
    int numTrees(int n) {
        vector<int> v(n+1,0);
        v[0]=1;
        v[1]=1;
        for(int i=2;i<n+1;i++){
            int j=0;
            int k=i-1;
            int tmp=0;
            if(i&1){
                while(j<k){
                    tmp+=(v[j]*v[k]);
                    j++;
                    k--;
                }
                tmp*=2;
                tmp+=(v[i/2]*v[i/2]);
                v[i]=tmp;
            }else{
                while(j<k){
                    tmp+=(v[j]*v[k]);
                    j++;
                    k--;
                }
                tmp*=2;
                v[i]=tmp;
            }
        }
        /*
        cout<<"\n";
        for(auto i : v){
            cout<<i<<" ";
        }
        */
        return v[n];
    }
};
