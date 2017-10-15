#include <bits/stdc++.h>
using namespace std;
int main(){
int n;
int cnt=0;
cin>>n;
string s[100];
for(int i=0;i<n;i++){
	cin>>s[i];
}
for(int i=0;i<n;i++){
	string a=s[i];
	for(int i=0;i<a.length();i++){
		if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'){
			continue;
		}
		else{
			cnt++;
			//cout<<"counnter is incrimented by 1 for"<<a[i]<<endl;
		}
	}
	cout<<(cnt-3)<<"/"<<a.length()<<endl;
	cnt=0;
}
return 0;
}
