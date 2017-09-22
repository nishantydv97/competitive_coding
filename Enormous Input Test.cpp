#include<iostream>
using namespace std;
int main(){
	int n,k;
	int cnt=0;
	cin>>n>>k;
	int t[n];
	for(int i=0;i<n;i++){
		cin>>t[i];
		cout<<"\n";
	}
	for(int i=0;i<n;i++){
		if((t[i]%k)==0)
			cnt++;
	}
	cout<<cnt;
}
