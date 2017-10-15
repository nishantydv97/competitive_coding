#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }

    int typeCheck [2][5] = {0};
    for(int i=0; i<n; i++) {
        if(ar[i]==1) {
            typeCheck[0][0]++;
            typeCheck[1][0] = ar[i];
        }
        if(ar[i]==2) {
            typeCheck[0][1]++;
            typeCheck[1][1] = ar[i];
        }
        if(ar[i]==3){
            typeCheck[0][2]++;
            typeCheck[1][2] = ar[i];
        }
        if(ar[i]==4) {
            typeCheck[0][3]++;
            typeCheck[1][3] = ar[i];
        }
        if(ar[i]==5) {
            typeCheck[0][4]++;
            typeCheck[1][4] = ar[i];
        }
    }
    int maxVal = typeCheck[0][0];
    int commonBird;
    for(int k=0; k<5;k++) {
        if(typeCheck[0][k]>maxVal) {
            maxVal = typeCheck[0][k];
            commonBird = typeCheck[1][k];
        }
    }
    cout << commonBird;
    return 0;
}

