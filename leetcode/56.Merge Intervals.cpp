/*
problem link : https://leetcode.com/problems/merge-intervals/


Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.


*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        map<int,int> mp;
        vector<vector<int>> v;
        if(intervals.size()==0){
            return v;
        }
        for(auto i :  intervals){
            if(mp.find(i[0])==mp.end()){
                mp[i[0]]=i[1];
            }else{
                mp[i[0]]=max(mp[i[0]],i[1]);
            }
            
        }
        /*
        for(auto i  : mp){
            cout<<i.first<<" "<<i.second<<endl;
        }
        */
        map<int,int> :: iterator it = mp.begin();
        it++;
        map<int,int> :: iterator tmp = mp.begin();
        pair<int,int> tmpp=make_pair(tmp->first,tmp->second);
        for(it;it!=mp.end();it++){
            //cout<<it->first<<" "<<it->second<<endl;
            if(tmpp.second>=it->first){
                tmpp=make_pair(min(tmpp.first,it->first),max(tmpp.second,it->second));
            }else{
                vector<int> vi = {tmpp.first,tmpp.second};
                v.push_back(vi);
                tmpp=make_pair(it->first,it->second);
            }
        }
        vector<int> vi = {tmpp.first,tmpp.second};
        v.push_back(vi);
        return v;
    }
};
