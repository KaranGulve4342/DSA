// // CSES PROBLEM SET

// // EVERY PROBLEM IS SOLVABLE

// #include<bits/stdc++.h>
// using namespace std;

// #define int long long
// #define MOD 1000000007

// int solve(int idx, int amount, vector<int>& coins,vector<vector<int>>& dp){
//     if(amount == 0){
//         return 1;
//     }

//     if(idx < 0 || amount < 0){
//         return 0;
//     }

//     if(dp[idx][amount] != -1){
//         return dp[idx][amount];
//     }

//     int ways = 0;

//     for(int coinAmount = 0;coinAmount <= amount;coinAmount += coins[idx]){
//         ways = (ways + solve(idx - 1, amount - coinAmount, coins, dp)) % MOD;
//     }

//     return dp[idx][amount] = ways;
// }

// signed main(){
//     int n;
//     int amount;

//     cin >> n;
//     cin >> amount;

//     vector<int> coins(n);

//     for(int i = 0;i < n;i++){
//         cin >> coins[i];
//     }

//     // vector<vector<int>> dp(n+1, vector<int>(amount + 1, -1));

//     // cout<<solve(n-1,amount, coins, dp) % MOD<<endl;

//     vector<vector<int>> dp(n+1, vector<int>(amount + 1, 0));

//     for(int i = 0;i <= n;i++){
//         dp[i][0] = 1;
//     }

//     for(int i = 1;i <= n;i++){
//         for(int j = 0;j <= amount;j++){
//             dp[i][j] = dp[i-1][j];

//             if(j - coins[i-1] >= 0){
//                 dp[i][j] = (dp[i][j] + dp[i][j - coins[i-1]]) % MOD;
//             }
//         }
//     }

//     cout<<dp[n][amount]<<endl;

//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MOD 1000000007

int solve(int n, int amount, vector<int>& coins) {
    vector<int> dp(amount + 1, 0);

    // Base Case: There's exactly 1 way to form amount 0: by choosing no coins.
    dp[0] = 1;

    // Fill the dp array
    for (int i = 0; i < n; i++) { // Loop over each coin
        for (int j = coins[i]; j <= amount; j++) { // Update dp array for each amount
            dp[j] = (dp[j] + dp[j - coins[i]]) % MOD;
        }
    }

    return dp[amount];
}

signed main() {
    int n, amount;

    cin >> n >> amount;

    vector<int> coins(n);

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    cout << solve(n, amount, coins) % MOD << endl;

    return 0;
}
