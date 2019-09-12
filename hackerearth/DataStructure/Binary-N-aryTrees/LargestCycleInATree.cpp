/*

 You are given a tree of N  nodes and N-1  edges. Now you need to select two nodes a and b in the tree such that the cycle that will be formed after adding an edge between the two nodes a and b, its length should be maximum. If there are more than one possible answers, you can output any of them.

Input
The first line contains an integer N as input. Next N-1 lines contain a pair of integers (a,b) that denote there is an edge between the two nodes a and b in the tree.

Output
In the output, you need to print two integers separated by space which denote the nodes between which you can add the edge so as to maximize the length of the cycle in the tree.

Constraints:
1<=N<=10^5

SAMPLE INPUT
7
1 2
1 3
2 4
2 5
3 6
3 7
SAMPLE OUTPUT
4 6

Explanation
If you add an edge between the nodes 4 and 6 then you see that it forms the largest cycle in the tree. Some other possible outputs are -  5 6 or 5 7.


*/



/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/
// Write your code here
#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define fi first
#define se second
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define all(x) (x).begin(), (x).end()
#define ldb ldouble

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<db, db> pdd;



ll bfs(ll u, vector<int> g[]){
    int dis[100001];
    memset(dis,-1,sizeof(dis));

    queue<ll> q;
    q.push(u);
    dis[u]=0;
    while(!q.empty()){
        int t=q.front();
        q.pop();
        for(auto i : g[t]){
            int v = i;
            if(dis[v]==-1){
                q.push(v);
                dis[v]=dis[t]+1;
            }
        }
    }
    ll node=0;
    ll index;
    for(ll i=0;i<10001;i++){
        if(dis[i]>node){
            node=dis[i];
            index=i;
        }
    }
    return index;
}



int main(){
    ll n;
    ll u,v;
    cin>>n;
    vector<int> g[n+1];
    while(--n){
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    /*
    for(auto i : g){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    */
    ll first = bfs(1,g);
    ll second = bfs(first,g);
    cout<<first<<" "<<second;
    return 0;
}
