/*


Given n, i.e. total number of nodes in an undirected graph numbered from 1 to n and an integer e, i.e. total number of edges in the graph. Calculate the total number of connected components in the graph. A connected component is a set of vertices in a graph that are linked to each other by paths.

Input Format:

First line of input line contains two integers n and e. Next e line will contain two integers u and v meaning that node u and node v are connected to each other in undirected fashion. 

Output Format:

For each input graph print an integer x denoting total number of connected components.

Constraints:

All the input values are well with in the integer range.

SAMPLE INPUT 
8 5
1 2
2 3
2 4
3 5
6 7



*/




#include<bits/stdc++.h>
using namespace std;

void dfs(int n, vector<int> v[], vector<bool> &(vis),  int s){
    if(!vis[s]){
        vis[s]=1;
        for(auto i : v[s]){
            dfs(n, v, vis, i);
        }
    }
}

int main(){
    int n,e;
    cin>>n>>e;
    vector<int> v[n+1];
    while(e--){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    vector<bool> vis(n+1,0);
    int ans=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            ans++;
            dfs(n+1, v, vis, i);
        }
    }
    cout<<ans<<"\n";
}
