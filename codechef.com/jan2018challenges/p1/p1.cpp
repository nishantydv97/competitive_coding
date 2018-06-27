/*
You are given four integers a, b, c and d. Determine if there's a rectangle such that the lengths of its sides are a, b, c and d (in any order).
Input

    The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
    The first and only line of each test case contains four space-separated integers a, b, c and d.

Output

For each test case, print a single line containing one string "YES" or "NO".
Constraints

    1 ≤ T ≤ 1,000
    1 ≤ a, b, c, d ≤ 10,000

Subtasks

Subtask #1 (100 points): original constraints
Example

Input:

3
1 1 2 2
3 2 2 3
1 2 2 2

Output:

YES
YES
NO

*/
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	int cnt=0;
	cin>>n;
	string s="YES";
	int arr[4];
	for(int i=0;i<n;i++){
		for(int j=0;j<4;j++){
			cin>>arr[j];
		}
		for(int j=0;j<4;j++){
		    for(int k=0;k<4;k++){
		        if(arr[j]==arr[k]){
		            cnt++;
		        }
		    }
		    if(cnt==1 or cnt==3){
		        s="NO";
		        cnt=0;
		    }else{
		        cnt=0;
		    }
		}
		cout<<s<<endl;
		s="YES";
	//	cout<<"value of cnt is  "<<cnt<<endl;
	}
    return 0;
}



