// CSES DP PROBLEM

// SAME AS COIN CHANGE II PROBLEM ON LEETCODE

vector<vector<int>> dp;

#include <bits/stdc++.h>
using namespace std;

int solve(int idx, int amount, vector<int>& coins){
    if(idx < 0){
        return 0;
    }

    if(amount == 0){
        return 1;
    }

    if(dp[idx][amount] != -1){
        return dp[idx][amount];
    }

    int ways = 0;

    for(int coinAmount = 0;coinAmount <= amount;coinAmount += coins[idx]){
        ways = (ways + solve(idx-1, amount - coinAmount, coins)) % 1000000007;
    }

    return dp[idx][amount] = ways;
}


int main(){
    int n, amount;

    cin >> n >> amount;

    vector<int> coins(n);
    for(int i = 0;i < n;i++){
        cin >> coins[i];
    }

    dp.resize(n+1, vector<int>(amount+1, -1));

    int ans = solve(n-1, amount, coins);

    cout << ans << endl;

    return 0;
    
}