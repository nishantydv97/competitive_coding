
/*

After a hectic week at work, Mancunian and Liverbird decide to go on a fun weekend camping trip. As they were passing through a forest, they stumbled upon a unique tree of N nodes. Vertices are numbered from 1 to N.

Each node of the tree is assigned a color (out of C possible colors). Being bored, they decide to work together (for a change) and test their reasoning skills. The tree is rooted at vertex 1. For each node, they want to find its closest ancestor having the same color.

Input format
The first line contains two integers N and C denoting the number of vertices in the tree and the number of possible colors.
The second line contains N-1 integers. The ith integer denotes the parent of the i+1th vertex.
The third line contains N integers, denoting the colors of the vertices. Each color lies between 1 and C inclusive.

Output format
Print N space-separated integers. The Ith integer is the vertex number of lowest ancestor of the Ith node which has the same color. If there is no such ancestor, print 1 for that node.

Constraints
SAMPLE INPUT 
5 4
1 1 3 3
1 4 2 1 2
SAMPLE OUTPUT 
-1 -1 -1 1 3
Explanation
Vertices 1, 2 and 3 do not have any ancestors having the same color as them. The nearest required ancestors for vertices 4 and 5 are vertices 1 and 3 respectively.

Time Limit:	2.0 sec(s) for each input file.
Memory Limit:	256 MB
Source Limit:	1024 KB
Marking Scheme:	Marks are awarded when all the testcases pass.

*/




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
#define MAX 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<db, db> pdd;


int main(){
    fast
    ll n,c;
    cin>>n>>c;
    map<ll,ll> s;
    s[1]=-1;
    FOR(i,2,n+1){
        ll tmp;
        cin>>tmp;
        s[i]=tmp;
    }
    
    vector<ll> v;
    v.pb(-1);
    rep(i,n){
        ll tmp;
        cin>>tmp;
        v.pb(tmp);
    }
    

    cout<<-1<<" ";
    FOR(i,2,n+1){
        ll j=i;
        ll col=v[j];

        ll ans=9999999;
        ans=s[j];

        while(1){
            
            if( v[ans] == col or ans == 1){
                if(v[ans]==col){
                    cout<<ans<<" ";
                    break;
                }else{
                    cout<<-1<<" ";
                    break;
                }
            }else{
                ans=s[ans];
            }
        }
    }
    
    
    return 0;
}
