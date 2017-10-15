#include <bits/stdc++.h>

using namespace std;

using namespace std;
vector < int > solve(int a0, int a1, int a2, int b0, int b1, int b2){
    // Complete this functionin
     //vector <int> :: iterator i;
    vector <int> g1;
    int a=0,b=0;
    if(a0>b0){
        ++a;
    }else if(a0<b0)
        b++;
    else{

    }
    if(a1>b1){
        ++a;
    }else if(a1<b1)
        ++b;
    else{

    }
    if(a2>b2){
        ++a;
    }else if(a2<b2)
        ++b;
    else{

    }
    g1.push_back(a);
    g1.push_back(b);
    return g1;
}

int main() {
    int a0;
    int a1;
    int a2;
    cin >> a0 >> a1 >> a2;
    int b0;
    int b1;
    int b2;
    cin >> b0 >> b1 >> b2;
    vector < int > result = solve(a0, a1, a2, b0, b1, b2);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? " " : "");
    }
    cout << endl;


    return 0;
}

