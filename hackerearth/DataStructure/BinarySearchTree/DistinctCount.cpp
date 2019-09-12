/*
 
 
Given an array A of N integers, classify it as being Good Bad or Average. It is called Good, if it contains exactly X distinct integers, Bad if it contains less than X distinct integers and Average if it contains more than X distinct integers.

Input format:
First line consists of a single integer T denoting the number of test cases.
First line of each test case consists of two space separated integers denoting N and X.
Second line of each test case consists of N space separated integers denoting the array elements.

Output format:
Print the required answer for each test case on a new line.



Sample Input

4
4 1
1 4 2 5
4 2
4 2 1 5
4 3
5 2 4 1
4 4
1 2 4 5


Sample Output

Average
Average
Average
Good




*/




#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        set<ll>s;
        cin>>n>>k;
        for(ll i=0;i<n;i++){
            ll in;
            cin>>in;
            s.insert(in);
        }
        if(s.size()==k){
            cout<<"Good"<<endl;
        }else if(s.size()>k){
            cout<<"Average"<<endl;
        }else{
            cout<<"Bad"<<endl;
        }
    }
    return 0;
}
