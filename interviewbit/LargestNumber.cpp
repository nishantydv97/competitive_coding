/*

Given a list of non negative integers, arrange them such that they form the largest number.

For example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.




*/


bool comp(string s1, string s2){
    string s1s2=s1+s2;
    string s2s1=s2+s1;
    return s1s2>s2s1;
}

string Solution::largestNumber(const vector<int> &A) {
    vector<string> vec;
    for(auto i : A){
        vec.push_back(to_string(i));
    }
    sort(vec.begin(), vec.end(), comp);
    string ans="";
    for(auto i : vec){
        ans+=i;
    }
    int i=0;
    while(i<ans.size() and ans[i]=='0'){
        i++;
    }
    //cout<<i<<endl;
    if(i>=ans.size()) return "0";
    
    return ans.substr(i, ans.size()-i);
}
