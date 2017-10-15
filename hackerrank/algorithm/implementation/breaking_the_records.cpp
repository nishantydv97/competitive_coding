#include <bits/stdc++.h>

using namespace std;

vector < int > getRecord(vector < int > s)
{
    int best=0,worst=0;
    int top=0,low=0;
    vector<int> ans;
    top=s[0];
    low=s[0];
    for(int i=1;i<s.size();i++){
    	if(s[i]>top){
    		best++;
    		//cout<<"best is :"<<best<<endl;
    		top=s[i];
    		//cout<<"top is :"<<top<<endl;
    	}else if(s[i]<low){
    		worst++;
    		//cout<<"worst is :"<<worst<<endl;
    		low=s[i];
    		//cout<<"low is :"<<low<<endl;
    	}else{
    		continue;
    	}
    }
    ans.push_back(best);
    ans.push_back(worst);

    return ans;

}

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    for(int s_i = 0; s_i < n; s_i++){
       cin >> s[s_i];
    }
    vector < int > result = getRecord(s);
    /*string separator = "", delimiter = " ";
    for(auto val: result) {
        cout<<separator<<val;
        separator = delimiter;
    }
    cout<<endl;*/
    cout<<result[0]<<" "<<result[1];
    return 0;
}
