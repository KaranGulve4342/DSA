// LEETCODE

/*
int solveTab(vector<int>& prices, int fee){
    int n = prices.size();

    vector<int> curr(2, 0);
    vector<int> next(2, 0);

    for(int index = n-1;index >= 0;index--){
        for(int buy = 0;buy <= 1;buy++){
            int profit = 0;
            if(buy){
                int buyKaro = -prices[index] + next[0];
                int skipKaro = 0 + next[1];
                profit = max(buyKaro, skipKaro);
            }
            else{
                int sellKaro = prices[index] + next[1] - fee;
                int skipKaro = 0 + next[0];
                profit = max(sellKaro, skipKaro);
            }
            curr[buy] = profit;
        }
        next = curr;
    }
    return next[1];
}
int maxProfit(int fee, vector<int>& prices){
    return solveTab(prices, fee);
}
*/

// USING TABULATION

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        for(int idx = n-1;idx >= 0;idx--){
            for(int buy = 0;buy <= 1; buy++){
                if(buy == 1){
                    dp[idx][buy] = max((-prices[idx] + dp[idx + 1][0]), (0 + dp[idx + 1][1]));
                }
                else{
                    dp[idx][buy] = max((prices[idx] - fee + dp[idx + 1][1]), (0 + dp[idx + 1][0]));
                }
            }
        }

        return dp[0][1];
    }
};