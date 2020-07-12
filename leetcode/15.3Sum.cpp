/*

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> x;
        unordered_map<int,int> ump;
        if(nums.size()<3){
            return x;
        }
        
        
        unordered_map<int,int> vis;
        for(auto i : nums){
            ump[i]++;
            vis[i]=0;
        }
        if(ump[0]==nums.size())
        {
            return {{0,0,0}};
        }
        if(ump[0]>=3)
        {
            x.push_back({0,0,0});
        }
        /*
        for(auto i : ump){
            cout<<i.first<<" "<<i.second<<"  "<<endl;;
        }
        cout<<"hola"<<endl;
        */
        
        unordered_map<int,int> :: iterator it;
        for(it=ump.begin();it!=ump.end();it++){
            unordered_map<int,int> :: iterator it1;
            for(it1=ump.begin();it1!=ump.end();it1++){
                if(it1==it) continue;

                if(ump.find(-(it->first+it1->first))!=ump.end()){
                    unordered_map<int,int> :: iterator it3=ump.find(-(it->first+it1->first));   
                    vector<int> vi;
                    
                    /*
                    cout<<"output is "<<endl;
                    cout<<it->first<<it1->first<<it3->first<<endl;
                    cout<<it->second<<it1->second<<it3->second<<endl;
                    cout<<"output end is  "<<endl;
                    */
                    int f1,f2,f3;
                    f1=f2=f3=0;
                    if(it->second){
                        vi.push_back(it->first);
                        it->second--;
                        f1=1;
                    }
                    if(it1->second){
                        vi.push_back(it1->first);
                        it1->second--;
                        f2=1;
                    }
                    if(it3->second){
                        vi.push_back(it3->first);
                        it3->second--;
                        f3=1;
                    }
                    //cout<<it->first<<" "<<it1->first<<" "<<it3->first<<" "<<endl;
                    if(vi.size()==3){
                        vector<int> vt;
                        vt.push_back(it->first);
                        vt.push_back(it1->first);
                        vt.push_back(it3->first);
                        sort(vt.begin(),vt.end());
                        x.push_back(vt);
                        vt.clear();
                        //cout<<it->first<<" "<<it1->first<<" "<<it3->first<<" "<<endl;
                    }
                        if(f1){
                            it->second++;

                        }
                        if(f2){
                            it1->second++;
                        }
                        if(f3){
                            it3->second++;
                        }
                        f1=f3=f3=0;
                    
                    
                }

            }
        }
        sort(x.begin(),x.end());
        x.resize(unique(x.begin(),x.end())-x.begin());
        
        return x;
    }
};
