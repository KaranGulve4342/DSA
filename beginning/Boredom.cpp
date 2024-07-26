// CODEFORCES 1500 RATED



#include <bits/stdc++.h>
using namespace std;

#define int long long

const int maxi = 1e5 + 1;

int solve(int idx, vector<int>& freq, vector<int>& dp) {
    if (idx >= maxi) {
        return 0;
    }

    if (dp[idx] != -1) {
        return dp[idx];
    }

    int pick = freq[idx] * idx + solve(idx + 2, freq, dp);
    int skip = solve(idx + 1, freq, dp);

    return dp[idx] = max(pick, skip);
}

signed main() {
    
    int n;
    cin >> n;

    vector<int> freq(maxi, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }

    vector<int> dp(maxi, -1);

    cout << solve(1, freq, dp) << endl;
}
