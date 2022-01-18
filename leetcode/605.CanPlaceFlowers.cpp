/*

You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule.

 

Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
Example 2:

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false
 

Constraints:

1 <= flowerbed.length <= 2 * 104
flowerbed[i] is 0 or 1.
There are no two adjacent flowers in flowerbed.
0 <= n <= flowerbed.length
Accepted
263,505
Submissions
800,600


*/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0) return true;
        if(flowerbed.size()==0){
            if(n==0) return 1;
            return 0;
        }
        
        if(flowerbed.size()==1){
            if((n==1 or n==0) and flowerbed[0]==0) return 1;
            return 0;
        }
        
        vector<int> v;
        for(int i=0; i<flowerbed.size(); i++){
            if(flowerbed[i]){
                v.push_back(i);
            }
        }
        int cnt=0;
        if(v.size()==0){
            cnt = (flowerbed.size()+1)/2;
            if(cnt>=n) return true;
            return false;
        }
        
        cnt=((v[0]-0)/2)+(flowerbed.size()-1-v[v.size()-1])/2;
        if(v.size()==1){
            if(cnt>=n) return true;
            return false;
        }
        int i=0;
        int j=1;
        while(j<v.size()){
            cnt+=((v[j]-2-v[i])/2);
            i++;
            j++;
        }
        if(cnt>=n) return true;
        return false;
        
    }
};
