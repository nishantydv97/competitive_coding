/*

You are given N number of books. Every ith book has Pi number of pages. 
You have to allocate books to M number of students. There can be many ways or permutations to do so. In each permutation one of the M students will be allocated the maximum number of pages. Out of all these permutations, the task is to find that particular permutation in which the maximum number of pages allocated to a student is minimum of those in all the other permutations, and print this minimum value. 
Each book will be allocated to exactly one student. Each student has to be allocated atleast one book.
Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see explanation for better understanding).

Input:
The first line contains 'T' denoting the number of testcases. Then follows description of T testcases:Each case begins with a single positive integer N denoting the number of books.The second line contains N space separated positive integers denoting the pages of each book.And the third line contains another integer M, denoting the number of students.

Output:
For each test case, output a single line containing minimum number of pages each student has to read for corresponding test case.

Expected Time Complexity: O(NLogN).
Expected Auxiliary Space: O(1).

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= A [ i ] <= 106
1 <= M <= 106

Example:
Input:
2
4
12 34 67 90
2
3
15 17 20
2
Output:
113
32

Explaination:
Testcase 1:Allocation can be done in following ways:
{12} and {34, 67, 90}     Maximum Pages = 191
{12, 34} and {67, 90}     Maximum Pages = 157
{12, 34, 67} and {90}        Maximum Pages = 113

Therefore, the minimum of these cases is 113, which is selected as output.

Testcase 2: Allocation can be done in following ways:
{15} and {17, 20} Maximum pages = 37
{15, 17} and {20} Maximum Pages = 32

So, the output will be 32.



*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isPossible(vector<ll> &v, ll n, ll m, ll bucket){
    if(*max_element(v.begin(),v.end())>bucket) return false;
    ll pages=v[0];
    ll total_student=1;
    for(ll i=1;i<n;i++){
        if(pages+v[i]<=bucket){
            pages+=v[i];
        }else{
            total_student++;
            pages=v[i];
        }
        //cout<<"pages is "<<pages<<endl;
    }
    //cout<<total_student<<"  "<<bucket<<endl;
    return total_student<=m ? true : false;
}

void solve(vector<ll>& v, ll n , ll m, ll start, ll end, ll & ans){
    //cout<<"start is "<<start<<" end is "<<end<<endl;

    if(start<=end){
        ll mid=start+(end-start)/2;    
        //cout<<mid<<endl;
        if(isPossible(v,n,m,mid)){
            ans=min(ans,mid);
            solve(v,n,m,start,mid-1,ans);
        }else{
            solve(v,n,m,mid+1,end,ans);
        }
    }
    
}

int main() {
/*
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
*/
	ll t;
	cin>>t;
	while(t--){
	    ll n;
	    cin>>n;
	    vector<ll> v(n,0);
        ll sum=0;
	    for(ll i=0;i<n;i++){
	        cin>>v[i];
            sum+=v[i];
	    }
	    ll m;
	    cin>>m;
        ll ans=INT_MAX;
	    if(m>n){
            cout<<-1<<endl;
        }else{
            if(m==n){
                cout<<*max_element(v.begin(),v.end())<<endl;
            }else{
                solve(v,n,m,1,sum,ans);
                cout<<ans<<endl;
            }
        }
	}
	return 0;
}
