// CSES

// EVERY PROBLEM IS SOLVABLE


#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MOD 1000000007

int solve(int amount, vector<int>& coins, vector<int> &dp){
    if(amount == 0){
        return 1;
    }

    if(amount < 0){
        return 0;
    }

    if(dp[amount] != -1){
        return dp[amount];
    }

    int ways = 0;

    for(auto coin : coins){
        if(amount - coin >= 0){
            ways = (ways + solve(amount - coin, coins, dp)) % MOD;
        }
    }

    return dp[amount] = ways;
}

signed main(){
    int n, amount;

    cin >> n >> amount;

    vector<int> coins(n);

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<int> dp(amount + 1, -1);

    cout << solve(amount, coins, dp) % MOD << endl;

    return 0;
}