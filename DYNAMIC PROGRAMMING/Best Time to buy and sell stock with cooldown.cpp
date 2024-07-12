// LEETCODE 309

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int idx, int buy, vector<int>& prices, vector<vector<int>>& dp){
        if(idx >= prices.size()){
            return 0;
        }

        if(dp[idx][buy] != -1){
            return dp[idx][buy];
        }

        if(buy){
            int buyKaro = -prices[idx] + solve(idx + 1, 0, prices, dp);
            int skipKaro = 0 + solve(idx + 1, 1, prices, dp);

            return dp[idx][buy] = max(buyKaro, skipKaro);
        }
        else{
            int sellKaro = prices[idx] + solve(idx + 2, 1, prices, dp);
            int skipKaro = 0 + solve(idx + 1, 0, prices, dp);

            return dp[idx][buy] = max(sellKaro, skipKaro);
        }

        return 0;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n+1, vector<int>(2, -1));

        return solve(0, 1, prices, dp);
    }
};