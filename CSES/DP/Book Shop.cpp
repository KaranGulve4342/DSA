// CSES PROBLEM SET

// EVERY PROBLEM IS SOLVABLE

#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, x;
vector<int> prices, pages;
// vector<vector<int>> dp;

// int maxPages(int i, int remainingBudget) {
//     if (i == n || remainingBudget == 0) {
//         return 0;
//     }

//     if (dp[i][remainingBudget] != -1) {
//         return dp[i][remainingBudget];
//     }

//     int result = maxPages(i + 1, remainingBudget);

//     if (remainingBudget >= price[i]) {
//         result = max(result, pages[i] + maxPages(i + 1, remainingBudget - price[i]));
//     }

//     return dp[i][remainingBudget] = result;
// }

signed main() {
    cin >> n >> x;

    prices.resize(n);
    pages.resize(n);
    for (int i = 0; i < n; i++) cin >> prices[i];
    for (int i = 0; i < n; i++) cin >> pages[i];

    // dp.resize(n+1, vector<int>(x + 1, -1));

    // int dp[n + 1][x + 1];

    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= x; j++) {
    //         dp[i][j] = 0;
    //     }
    // }

    // cout << maxPages(0, x) << endl;

    // dp.resize(n + 1, vector<int>(x + 1, 0));

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 0; j <= x; j++) { 
    //         dp[i][j] = dp[i - 1][j]; 

    //         if (price[i - 1] <= j) {
    //             dp[i][j] = max(dp[i][j], pages[i - 1] + dp[i - 1][j - price[i - 1]]); // Include the current book
    //         }
    //     }
    // }

    // cout << dp[n][x] << endl;

    vector<int> dp(x + 1, 0);

    for(int i = 0;i < n;i++){
        for(int j = x;j >= prices[i];j--){
            dp[j] = max(dp[j], pages[i] + dp[j - prices[i]]);
        }
    }

    cout << dp[x] << endl;

    return 0;
}