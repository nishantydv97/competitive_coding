#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
using namespace std;
int main(){
  long long num;
  while(cin>>num){
      if(num==0)
          cout<<"0"<<endl;
      else if(num%2)
          cout<<"1"<<endl;
      else{
          int cnt=0;
          while(num%2 == 0){
              cnt++;
              num=num/2;
          }
          cout<<pow(2,cnt)<<endl;
      }
  }
  return 0;
}
