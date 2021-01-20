/*

Given an array A containing 2*N+2 positive numbers, out of which 2*N numbers exist in pairs whereas the other two number occur exactly once and are distinct. Find the other two numbers  (in ascending order).

Example 1:


Input: 
2
1 2 3 2 1 4
Output:
3 4 
Explanation: 3 and 4 occur exactly once.
Example 2:

Input:
1
2 1 3 2
Output:
1 3
Explanation: 1 3 occur exactly once.
Your Task:
You do not need to read or print anything. Your task is to complete the function singleNumber() which takes the array as input parameter and returns a list of two numbers which occur exactly once in the array.

Expected Time Complexity: O(n)
Expected Space Complexity: O(1)

Constraints:
1 <= length of array <= 106 
1 <= Elements in array <= 5 * 106

*/


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
public:
    int kthSetBit(int n){
        int k=0;
        while(!(n & 1)){
            n>>=1;
            k++;
        }
        return k;
    }
    bool ifKthBitSet(int n, int k){
        while(k--){
            n>>=1;
        }
        return n&1;
    }
    vector<int> singleNumber(vector<int>& nums) 
    {
        int vectorXor=0;
        for(auto i : nums){
            vectorXor^=i;
        }
        int kthBit=kthSetBit(vectorXor);
        vector<int> kthSetBit;
        vector<int> kthUnsetBit;
        for(auto i : nums){
            if(ifKthBitSet(i,kthBit)){
                kthSetBit.push_back(i);
            }else{
                kthUnsetBit.push_back(i);
            }
        }
        int firstUniqueNumber=0;
        int secondUniqueNumber=0;
        for(auto i : kthSetBit){
            firstUniqueNumber^=i;
        }
        for(auto i : kthUnsetBit){
            secondUniqueNumber^=i;
        }
        vector<int> ans;
        ans.push_back(firstUniqueNumber);
        ans.push_back(secondUniqueNumber);
        sort(ans.begin(), ans.end());
        
        
        return ans;
    }
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}  // } Driver Code Ends
