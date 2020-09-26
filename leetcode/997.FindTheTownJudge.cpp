/*


In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.

If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.

 

Example 1:

Input: N = 2, trust = [[1,2]]
Output: 2
Example 2:

Input: N = 3, trust = [[1,3],[2,3]]
Output: 3
Example 3:

Input: N = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1
Example 4:

Input: N = 3, trust = [[1,2],[2,3]]
Output: -1
Example 5:

Input: N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
Output: 3
 

Constraints:

1 <= N <= 1000
0 <= trust.length <= 10^4
trust[i].length == 2
trust[i] are all different
trust[i][0] != trust[i][1]
1 <= trust[i][0], trust[i][1] <= N


*/



class Solution {
public:
    int findJudge(int n, vector<vector<int>>& t) {
        if(n==1) return 1;
        if(t.size()==0) return -1;
        vector<vector<int>> v(n+1, vector<int>(n+1, 0));
        for(auto i : t){
            v[i[0]][i[1]]=1;
        }
        int i=1;
        int j=n;
        while(i<j){
            if(v[i][j]){
                i++;
            }else{
                j--;
            }
        }
        for(int k=0;k<n+1;k++){
            if(v[i][k] and k!=i){
                return -1;
            }
        }
        for(int k=1;k<n+1;k++){
            if(v[k][i]==0 and k!=i) return -1;
        }
        return i;
    }
};
