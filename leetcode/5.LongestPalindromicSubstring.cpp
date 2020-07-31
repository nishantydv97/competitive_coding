/*

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"

*/

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()==0){
            return s;
        }
        if(s.size()==1){
            return s;
        }
        int n=s.size();
    int ans=1;
	pair<int,int> p;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i=0;i<dp.size();i++){
		dp[i][i]=1;
	}
	for(int i=1;i<dp.size();i++){
		if(s[i]==s[i-1]){
			dp[i-1][i]=1;
			p=make_pair(i-1,i);
		}else{
			dp[i-1][i]=0;
		}
	}
    
    
	for(int i=2;i<n;i++){
		int j,k;
		j=i;
		k=0;
		
		while(j<n){
		    //cout<<j<<" "<<k<<endl;
			if(dp[k+1][j-1]==1 && s[k]==s[j]){
				dp[k][j]=1;
				if(abs(k-j)>ans){
					p=make_pair(k,j);
					ans=abs(j-k);
				}
			}else{
				dp[k][j]=0;
			}
			j++;
			k++;
		}
		
	}
	//cout<<p.first<<" "<<p.second<<endl;
	if(p.first>p.second){
	    swap(p.first,p.second);
	}
	string ans_str="";
	for(int i=p.first;i<=p.second;i++){
	    ans_str+=s[i];
	}
	return ans_str;
    }
};
