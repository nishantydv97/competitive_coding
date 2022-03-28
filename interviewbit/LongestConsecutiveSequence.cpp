/*

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Example: 

Given [100, 4, 200, 1, 3, 2],

The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.

*/


int Solution::longestConsecutive(const vector<int> &num) {
    unordered_map<int, int> ump;
    int maxi=INT_MIN;
    int mini=INT_MAX;
    for(auto i : num){
        ump[i]=1;
        maxi=max(maxi, i);
        mini=min(mini, i);
    }
    int res=0;
    int tmp=0;
    for(int i=mini; i<=maxi; i++){
        if(ump[i]){
            tmp++;
            res=max(res, tmp);
        }else{
            tmp=0;
        }
    }
    return res;

}


