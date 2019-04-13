#include <bits/stdc++.h> 
using namespace std; 

int main() 
{ 
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt=0;
    for(int i=0;i<n;i++){
        if((int)s[i]%2==0){
//            cout<<i<<" "<<s[i]<<endl;;
            cnt+=(i+1);
        }
    }
    cout<<cnt;

	return 0; 
} 

