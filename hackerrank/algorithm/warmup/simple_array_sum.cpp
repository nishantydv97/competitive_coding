#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int simpleArraySum(int n, vector <int> ar) {
    int num=0;
    int i;
    for(i=0;i<n;i++){
        num=num+ar[i];
    }
    return num;
    // Complete this function
}

int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    int result = simpleArraySum(n, ar);
    cout << result << endl;
    return 0;
}

