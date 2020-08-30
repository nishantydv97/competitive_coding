/*


You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3 
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Note:
You may assume that you have an infinite number of each kind of coin.


*/


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT_MAX);

        dp[0]=0;
        for(int i=0;i<coins.size();i++){
            for(int j=0;j<amount+1;j++){
                int newi;
                if(j-coins[i]<0 || dp[j-coins[i]]==INT_MAX){
                    newi=INT_MAX;
                }else{
                    
                    newi=1+dp[j-coins[i]];
                }
                dp[j]=min(dp[j],newi);
            }
        }
        if(dp[amount]==INT_MAX){
            return -1;
        }
        return dp[amount];
    }
};
