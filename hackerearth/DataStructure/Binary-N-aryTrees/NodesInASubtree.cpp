/*
 
 
You are given a rooted tree that contains N nodes. Each node contains a lowercase alphabet.

You are required to answer Q queries of type u,c, where u is an integer and c is a lowercase alphabet. The count of nodes in the subtree of the node u containing c is considered as the answer of all the queries. 

Input format

First line: Two space-separated integers N and Q respectively
Second line: A string s of length N (where the ith character of s represents the character stored in node i)
Next N-1 line: Two space-separated integers u and v denoting an edge between node u and node v.
Next Q lines: An integer u and a space-separated character c.
Output format
For each query, print the output in a new line.  
 

Constraints
1<=N.Q<=10^5
1<=u,v<=N
c is a lowercalse alphabate.
si is a lowercase alphabate for all 1<=i<=N.
1 is the root of the node..
Note: it is guaranteed that the input generates a valid tree.


SAMPLE INPUT
3 1
aba
1 2
1 3
1 a
SAMPLE OUTPUT
2

Explanation
Tree given in the sample input will look like that.


		1(a)

	/		\

2(b)				3(a)


Number of node in the subtree of node 1 having 'a'  store  in it is 2.


 
 */




#include<bits/stdc++.h>
using namespace std;

int cnt=0;
vector<int> g[100000];


void dfs(int s,char c,string &S, bool (&visited)[100000]){
    visited[s]=1;
    for(int i=0;i<g[s].size();i++){
        if( visited[g[s][i]] == 0){
            if(S[g[s][i]-1]==c){
                cnt++;
            }
            dfs(g[s][i],c,S,visited);
        }
    }
}

int main()
{
	int N, Q;
	string S;
	cin >> N >> Q;
	cin >> S;
	for(int i = 0; i < N - 1; i ++)
	{
		int u, v;
		cin >> u >> v;
	    // Process the Inputs of node details
	    g[u].push_back(v);
	}
	//dfs(1,'a');
	/*
	for(int i=0;i<3;i++){
	    for(int j=0;j<g[i].size();j++){
	        cout<<g[i][j]<<" ";
	    }
	    cout<<"\n";
	}
	*/
	while(Q --)
	{
		int u;
		char c;
		bool visited[100000]={0};
		cin >> u >> c;
		cnt=0;
		if(S[u-1]==c){
		    cnt++;
		}
		dfs(u,c,S,visited);
		cout<<cnt<<endl;
		// Process queries
	}
	return 0;
}
