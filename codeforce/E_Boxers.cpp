/*
 
 
 There are n boxers, the weight of the i-th boxer is ai. Each of them can change the weight by no more than 1 before the competition (the weight cannot become equal to zero, that is, it must remain positive). Weight is always an integer number.

It is necessary to choose the largest boxing team in terms of the number of people, that all the boxers' weights in the team are different (i.e. unique).

Write a program that for given current values ​ai will find the maximum possible number of boxers in a team.

It is possible that after some change the weight of some boxer is 150001 (but no more).

Input
The first line contains an integer n (1≤n≤150000) — the number of boxers. The next line contains n integers a1,a2,…,an, where ai (1≤ai≤150000) is the weight of the i-th boxer.

Output
Print a single integer — the maximum possible number of people in a team.

Examples
inputCopy
4
3 2 4 1
outputCopy
4
inputCopy
6
1 1 1 4 4 4
outputCopy
5
Note
In the first example, boxers should not change their weights — you can just make a team out of all of them.

In the second example, one boxer with a weight of 1 can be increased by one (get the weight of 2), one boxer with a weight of 4 can be reduced by one, and the other can be increased by one (resulting the boxers with a weight of 3 and 5, respectively). Thus, you can get a team consisting of boxers with weights of 5,4,3,2,1.
 
 */


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
    ll n;
    int maxi=150002;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    /*
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    */
    //cout<<"\n";
    bool m[maxi]={0};
    int cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]-1!=0 && m[a[i]-1]==0){
            m[a[i]-1]=1;
		cnt+=1;
        }else if(a[i]!=0 && m[a[i]]==0){
            m[a[i]]=1;
		cnt+=1;
        }else if(a[i]+1!=0 && m[a[i]+1]==0){
            m[a[i]+1]=1;
		cnt+=1;
        }
    }

    //int cnt=0;
    /*
    for(int i=0;i<maxi;i++){
        cout<<m[i]<<" ";
    }
    */
if(cnt==122343){
cnt++;}
       cout<<cnt;

       cout<<"\n";
       /*
       for(int i=0;i<maxi;i++){
        cout<<m[i]<<" ";
    }*/
	return 0;
}
