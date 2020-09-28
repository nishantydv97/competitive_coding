/*


Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

Input: [1,2,3,0,2]
Output: 3 
Explanation: transactions = [buy, sell, cooldown, buy, sell]


*/



class Solution {
public:
    int helper(vector<int>& prices, int i, int avail, unordered_map<string, int>& ump){
        if(i>=prices.size()){
            return 0;
        }
        string key=to_string(i)+'|'+to_string(avail);
        int x;
        if(ump[key]){
            return ump[key];
        }
        if(avail){
            int buy=helper(prices, i+1, 0, ump) - prices[i];
            int notBuy=helper(prices, i+1, 1, ump);
            x=max(buy,notBuy);
        }else{
            int sail=helper(prices, i+2, 1, ump) + prices[i];
            int notSail=helper(prices, i+1, 0, ump);
            x=max(sail, notSail);
        }
        ump[key]=x;
        return x;
    }
    
    int maxProfit(vector<int>& prices) {
        unordered_map<string, int> ump;
        return helper(prices, 0, 1, ump);
    }
};
