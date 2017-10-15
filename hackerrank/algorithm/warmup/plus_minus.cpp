#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
    }
    int p=0,ni=0,z=0;
     for(int arr_i = 0;arr_i < n;arr_i++){
       if(arr[arr_i]<0){
           ni+=1;
       }
         else if(arr[arr_i]>0){
             p+=1;
         }
         else z+=1;
    }
    
    float f_p=(float)p/(float)n;
    float f_ni=(float)ni/(float)n;
    float f_z=(float)z/(float)n;
    cout<<f_p<<endl;
    cout<<f_ni<<endl;
    cout<<f_z<<endl;
    return 0;
}
