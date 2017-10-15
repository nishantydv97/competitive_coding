#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    int d1=0;
    int d2=0;
    int res;
    cin >> n;
    vector< vector<int> > a(n,vector<int>(n));
    for(int a_i = 0;a_i < n;a_i++){
       for(int a_j = 0;a_j < n;a_j++){
          cin >> a[a_i][a_j];
       }
    }
    int i=0,j=0;
    while(i<n){
        while(j<=i){
            if(i==j){
                d1=d1+a[i][j];
            }
            j+=1;
        }
        i+=1;
    }
    //i=n-1;
   /* while(i>=0){
        while(j<n){
            if(i==j){
                d2=d2+a[i][j];
            }
            j+=1;
        }
        i-=1;
    }*/
    int k=n-1;
    int l=0;
    while(k>=0){
        d2=d2+a[k][l];
        k-=1;
        l+=1;
    }
    res=d2-d1;
    if(res<0){
        res=(0-res);
        cout<<res;
    }
    else
        cout<<res;
  
}
 

