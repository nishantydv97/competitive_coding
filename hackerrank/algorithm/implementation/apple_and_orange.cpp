#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int s;
    int t;
    cin >> s >> t;
    int a;
    int b;
    cin >> a >> b;
    int m;
    int n;
    cin >> m >> n;
    vector<int> apple(m);
    for(int apple_i = 0;apple_i < m;apple_i++){
       cin >> apple[apple_i];
    }
    vector<int> orange(n);
    for(int orange_i = 0;orange_i < n;orange_i++){
       cin >> orange[orange_i];
    }
    int a_cnt=0,o_cnt=0;
    for(int i=0;i<m;i++){
        if(((a+apple[i])>=s)&((a+apple[i])<=t)){
            a_cnt++;
        }
    }
    for(int i=0;i<n;i++){
        if(((b+orange[i])>=s)&((b+orange[i])<=t)){
            o_cnt++;
        }
    }
    cout<<a_cnt<<endl;
    cout<<o_cnt<<endl;
    return 0;
}

