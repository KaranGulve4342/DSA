// CSES DP PROBLEM
// SAME AS COIN CHANGE PROBLEM ON LEETCODE

#include <bits/stdc++.h>
using namespace std;

int solve(int amount, vector<int>& coins, vector<int>& dp){
    if(dp[amount] != INT_MAX){
        return dp[amount];
    }

    if(amount == 0){
        return 0;
    }

    int ans = INT_MAX;
    for(auto coin : coins){
        if(amount - coin >= 0){
            ans = min(ans + 0LL, solve(amount - coin, coins, dp) + 1LL);
        }
    }

    return dp[amount] = ans;
}

int main(){
    int n;
    int amount;
    cin >> n >> amount;

    vector<int> coins(n);
    for(int i = 0;i < n;i++){
        cin >> coins[i];
    }
   
    vector<int> dp(amount+1, INT_MAX);

    int ans = solve(amount, coins, dp);

    if(ans == INT_MAX){
        cout << -1 << endl;
    }
    else{
        cout << ans << endl;
    }
    return 0;
}