#include <bits/stdc++.h>

using namespace std;

int divisibleSumPairs(int n, int k, vector <int> ar) {
    // Complete this function
    int cnt=0;
    int sum;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            sum=ar[i]+ar[j];
            if((sum%k)==0){
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    int n;
    int k;
    cin >> n >> k;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    int result = divisibleSumPairs(n, k, ar);
    cout << result << endl;
    return 0;
}

