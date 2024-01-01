// LEETCODE 122

/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i = 1;i < prices.size();i++){
            if(prices[i] > prices[i - 1]){
                profit += prices[i]-prices[i-1];
            }
        }
        return profit; 
    }
};

*/

// REUCRSION
/*
int solve(int index, int buy, vector<int>& prices){
    if(index == prices.size()){
        return 0;
    }

    int profit = 0;
    if(buy){
        int buyKaro = -prices[index] + solve(index + 1, 0, prices);
        int skipKaro = 0 + solve(index+1, 1, prices);
        profit = max(buyKaro, skipKaro);
    }
    else{
        int sellKaro = prices[index] + solve(index + 1, 1, prices);
        int skipKaro = 0 + solve(index + 1, 0, prices);
        profit = max(sellKaro, skipKaro);
    }
    return profit;
}
int maxProfit(vector<int>& prices){
    return solve(0, 1, prices);
}
*/

// RECURSION + MEMOISATION
/*
int solve(int index, int buy, vector<int>& prices, vector<vector<int> >&dp){
    if(index == prices.size()){
        return 0;
    }

    if(dp[index][buy] != -1){
        return dp[index][buy];
    }
    int profit = 0;
    if(buy){
        int buyKaro = -prices[index] + solve(index + 1, 0, prices, dp);
        int skipKaro = 0 + solve(index + 1, 1, prices, dp);
        profit = max(buyKaro, skipKaro);
    }
    else{
        int sellKaro = prices[index] + solve(index + 1, 1, prices, dp);
        int skipKaro = 0 + solve(index+1, 0, prices, dp);
        profit = max(sellKaro, skipKaro);
    }
    return dp[index][buy] = profit;
}
int maxProfit(vector<int>& prices){
    int n = prices.size();
    vector<vector<int> >dp(n, vector<int>(2, -1));
    return solve(0, 1, prices, dp);
}
*/

// TABULATION
/*
int solveTab(vector<int>& prices){
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
                int sellKaro = prices[index] + next[1];
                int skipKaro = 0 + next[0];
                profit = max(sellKaro, skipKaro);
            }
            curr[buy] = profit;
        }
        next = curr;
    }
    return next[1];
}
int maxProfit(vector<int>& prices){
    return solveTab(prices);
}
*/
