// CSES PROBLEM SET

// EVERY PROBLEM IS SOLVABLE
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MOD 1e9 + 7

int solve(int amount, vector<int>& coins, vector<int>& dp) {
    if (amount == 0) {
        return 0;
    }

    if (dp[amount] != -1) {
        return dp[amount];
    }

    int ans = LLONG_MAX;
    for (auto coin : coins) {
        if (amount - coin >= 0) {
            int subproblem = solve(amount - coin, coins, dp);
            if (subproblem != LLONG_MAX) {
                ans = min(ans, 1LL + subproblem);
            }
        }
    }

    return dp[amount] = ans;
}

signed main() {
    int n, amount;

    cin >> n >> amount;

    vector<int> coins(n);

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<int> dp(amount + 1, -1);

    int ans = solve(amount, coins, dp);

    if (ans == LLONG_MAX) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}
