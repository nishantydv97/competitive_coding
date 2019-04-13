#include <bits/stdc++.h> 
using namespace std; 

int main() 
{ 
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    for(int i=n-2;i>=0;i--){
        if(a[i]>=a[i+1]){
            a[i]=a[i+1]-1;
        }
    }
    long long int  sum=0;
    for(int i=0;i<n;i++){
        if(a[i]>=0){
            sum+=a[i];    
        }
        
    }
    cout<<sum;
	return 0; 
} 

