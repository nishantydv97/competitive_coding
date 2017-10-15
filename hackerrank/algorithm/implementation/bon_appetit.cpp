/*#include <bits/stdc++.h>

using namespace std;

int bonAppetit(int n, int k, int b, vector <int> ar) {
    // Complete this function
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=ar[i];
    }
    sum=sum/2;
    if(sum==b)
        cout<<"Bon Appetit";
    else
        return (b-sum);
}

int main() {
    int n;
    int k;
    cin >> n >> k;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    int b;
    cin >> b;
    int result = bonAppetit(n, k, b, ar);
    cout << result << endl;
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    int k;
    cin >> n >> k;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    int b;
    cin >> b;
    //int result = bonAppetit(n, k, b, ar);
    //cout << result << endl;
    int sum=0;
       for(int i=0;i<n;i++){
           sum+=ar[i];
       }
       sum=sum-ar[k];
        sum=sum/2;
       if(sum==b)
           cout<<"Bon Appetit";
       else
           cout<<abs(b-sum);
           
    return 0;
}

