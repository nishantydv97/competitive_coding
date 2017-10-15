#include <bits/stdc++.h>

using namespace std;

/*int birthdayCakeCandles(int n, vector <long> ar) {
    // Complete this function
    sort(ar.begin(),ar.begin()+n);
    long cnt=1;
    for(int i=n-1;i>=0;i--){
        if(ar[i]==ar[--i])
            cnt++;
        else
            break;
    }
    return cnt;
}

int main() {
    long n;
    cin >> n;
    vector<long> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    int result = birthdayCakeCandles(n, ar);
    cout << result << endl;
    return 0;
}*/
int main() {
    int n;
    cin>>n;
    int c[n],h=0,t=0;
    for(int i=0; i<n;i++)
        cin>>c[i];
    sort(c, c+n,greater<int>());
    h=c[0];
    for(int i=0; i<n; i++){
        if(h==c[i])
            t++;
    }
    cout<<t;
    return 0;
}
