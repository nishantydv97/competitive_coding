#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n;
    for(int i=n;i>0;i--){
        for(int j=i-1;j>0;j--){
           cout<<" ";
       }
       for(int k=i;k<=n;k++){
           cout<<"#";
       }
        cout<<"\n";
    }
    return 0;
}


