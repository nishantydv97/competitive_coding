/*
 
 
 
You are given integer n. You have to arrange numbers from 1 to 2n, using each of them exactly once, on the circle, so that the following condition would be satisfied:

For every n consecutive numbers on the circle write their sum on the blackboard. Then any two of written on the blackboard 2n numbers differ not more than by 1.

For example, choose n=3. On the left you can see an example of a valid arrangement: 1+4+5=10, 4+5+2=11, 5+2+3=10, 2+3+6=11, 3+6+1=10, 6+1+4=11, any two numbers differ by at most 1. On the right you can see an invalid arrangement: for example, 5+1+6=12, and 3+2+4=9, 9 and 12 differ more than by 1.


Input
The first and the only line contain one integer n (1≤n≤105).

Output
If there is no solution, output "NO" in the first line.

If there is a solution, output "YES" in the first line. In the second line output 2n numbers — numbers from 1 to 2n in the order they will stay in the circle. Each number should appear only once. If there are several solutions, you can output any of them.

Examples
inputCopy
3
outputCopy
YES
1 4 5 2 3 6 
inputCopy
4
outputCopy
NO
Note
Example from the statement is shown for the first example.

It can be proved that there is no solution in the second example.

 
 
 
 
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
	ll n;
	cin>>n;
	n*=2;
	ll sum1=1;
	ll sum2=n;
	ll i=2;
	bool f=1;
	ll ans[n];
	ans[0]=1;ans[n-1]=n;
	ll j=1;
	ll k=n/2;
	/*
	cout<<n<<" "<<endl;
	rep(i,n){
		cout<<ans[i]<<" ";
	}

	cout<<endl;
	*/
	while(i<n){
	    //cout<<"f is  "<<f<<"i is "<<i<<endl;
		if(f){
			sum2+=i;
			ans[k]=i;
			k++;
			i++;
			sum2+=i;
			ans[k]=i;
			k++;
			i++;
			f=!f;
		}else{
			sum1+=i;
			ans[j]=i;
			j++;
			i++;
			sum1+=i;
			ans[j]=i;
			j++;
			i++;
			f=!f;
		}
	}
	if(abs(sum1-sum2)==1){
	    cout<<"YES"<<endl;
	    rep(i,n){
		cout<<ans[i]<<" ";
	}
	}else{
	    cout<<"NO"<<endl;
	}


	return 0;
}
