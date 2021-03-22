/*

Starting with a positive integer N, we reorder the digits in any order (including the original order) such that the leading digit is not zero.

Return true if and only if we can do this in a way such that the resulting number is a power of 2.

 

Example 1:

Input: 1
Output: true
Example 2:

Input: 10
Output: false
Example 3:

Input: 16
Output: true
Example 4:

Input: 24
Output: false
Example 5:

Input: 46
Output: true
 

Note:

1 <= N <= 10^9


*/




class Solution {
public:
    bool check(map<char, int> mp1){
        for(auto i : mp1){
            if(i.second!=0) return false;
        }
        return true;
    }
    bool operation(map<char, int> mp1, string k){
        for(auto i : k){
            mp1[i]--;
        }
        return check(mp1);
    }
    bool reorderedPowerOf2(int N) {
        string k=to_string(N);
        map<char, int> mp;
        for(auto i : k) mp[i]++;
        int i=1;
        vector<int> v;
        int x=pow(10,k.size());
        while(i<x){
            v.push_back(i);
            i<<=1;
        }
        map<char, int> tmp=mp;
        auto j=lower_bound(v.begin(), v.end(), pow(10, k.size()-1));
        auto l=upper_bound(v.begin(), v.end(), pow(10, k.size()));
        while(j<l){
            //cout<<*j<<" ";
            tmp=mp;
            string m=to_string(*j);
            if(operation(tmp, m)) return true;
            tmp=mp;
            j++;
        }
        return false;
    }
};
