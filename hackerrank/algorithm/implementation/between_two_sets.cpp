#include <bits/stdc++.h>

using namespace std;
class abc{
public:
	int n;
	int m;
	int gcd(int , int );
	int getTotalX(vector <int> a, vector <int> b);
}o;
int abc :: gcd(int a,int b){
	if(a==0){
		return b;
	}
	else{
	return gcd(b%a,a);
	}
}
int abc :: getTotalX(vector <int> a, vector <int> b) {
	int v_gcd_a = a[0];
	for(int i=1;i<o.n;i++){
		v_gcd_a=(v_gcd_a*a[i])/(o.gcd(a[i],v_gcd_a));
	}
    int lcm =v_gcd_a;
	int v_gcd_b = b[0];
		for(int i=1;i<o.m;i++){
			v_gcd_b=o.gcd(b[i],v_gcd_b);
		}
    
	int cnt=0;
	for(int i=lcm;i<v_gcd_b;i++){
		if(((i%lcm)==0)&((v_gcd_b)%i==0)){
			cnt++;
		}
	}
	return ++cnt;
}

int main() {

    cin >> o.n >> o.m;
    vector<int> a(o.n);
    for(int a_i = 0; a_i < o.n; a_i++){
       cin >> a[a_i];
    }
    vector<int> b(o.m);
    for(int b_i = 0; b_i < o.m; b_i++){
       cin >> b[b_i];
    }

    int total = o.getTotalX(a, b);
    cout << total << endl;
    return 0;
}
