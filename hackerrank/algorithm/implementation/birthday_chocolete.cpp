#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector < int > s, int d, int m){
    // Complete this function
    int cnt;
    int sum=0;
    cnt=0;
    for(int i=0;i<=(n-m);i++){
        for(int j=i;j<(i+m);j++){
            sum=sum+s[j];
        }
        if(sum==d){
            cnt++;
        }
        sum=0;
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    for(int s_i = 0; s_i < n; s_i++){
       cin >> s[s_i];
    }
    int d;
    int m;
    cin >> d >> m;
    int result = solve(n, s, d, m);
    cout << result << endl;
    return 0;
}

