#include<iostream>
#include <iomanip>
using namespace std;
int main(){
	int x;
	float y;
	double balance;
cin>>x;
cin>>y;
 
if((x%5)==0){
	if((x+0.5)<y){
		balance=y-(x+0.5);
		cout<<fixed<<setprecision(2)<<balance;
		}
	else
		cout<<fixed<<setprecision(2)<<y;
		}
 
else
cout<<fixed<<setprecision(2)<<y;
return 0;
}
