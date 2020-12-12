/*


A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.

Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.

The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

 

Example 1:


Input: n = 4, edges = [[1,0],[1,2],[1,3]]
Output: [1]
Explanation: As shown, the height of the tree is 1 when the root is the node with label 1 which is the only MHT.
Example 2:


Input: n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
Output: [3,4]
Example 3:

Input: n = 1, edges = []
Output: [0]
Example 4:

Input: n = 2, edges = [[0,1]]
Output: [0,1]
 

Constraints:

1 <= n <= 2 * 104
edges.length == n - 1
0 <= ai, bi < n
ai != bi
All the pairs (ai, bi) are distinct.
The given input is guaranteed to be a tree and there will be no repeated edges.


*/


class Solution {
public:
    void printDis(vector<int>& dis){
        for(auto i : dis){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    unordered_map<int, vector<int>> constructGraph(vector<vector<int>> edges){
        unordered_map<int, vector<int>> graph;
        for(auto i : edges){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        return graph;
    }
    
    void dfs(unordered_map<int, vector<int>> & graph, vector<int>& vis, int curr, vector<int>& dis, int& prev, int& hight){
        if(!vis[curr]){
            vis[curr]=1;
            dis[curr]=dis[prev]+1;
            hight=max(hight, dis[curr]);
            for(auto i : graph[curr]){
                dfs(graph, vis, i, dis, curr, hight);
            }
            //printDis(dis);
        }
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        vector<int> vis(n, 0);
        vector<int> dis(n, 0);
        unordered_map<int, vector<int>> graph=constructGraph(edges);
        /*
        for(auto i : graph){
            cout<<i.first<<"-> ";
            for(auto j : i.second){
                cout<<j<<" ";
            }
            cout<<"\n";
        }
        
        int i=4;
        int hight=0;
        dfs(graph, vis, i, dis, i, hight);
        printDis(dis);
        */
        vector<int> visited(n,0);
        int hight=INT_MAX;
        vector<int> ans;
        if(edges.size()==0) return {0};
        for(auto i : graph){
            for(auto j : i.second){
                int tmp=0;
                dfs(graph, vis, j, dis, j, tmp);
                //cout<<j<<" "<<tmp<<endl;
                if(!visited[j]){
                    if(tmp<hight){
                        hight=tmp;
                        ans.clear();
                        ans.push_back(j);
                    }else if(tmp==hight){
                        ans.push_back(j);
                    }
                    visited[j]=1;
                }
                
                fill(dis.begin(), dis.end(), 0);
                fill(vis.begin(), vis.end(), 0);
            }
        }
        return ans;
    }
};
