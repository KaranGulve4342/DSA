// LEETCODE 3179

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        const int MOD = 1e9 + 7;

        vector<int> dp(n, 1);

        for(int t = 0;t < k;t++){
            for(int i = 1;i < n;i++){
                dp[i] = (dp[i] + dp[i-1]) % MOD;
            }
        }

        return dp[n-1];
    }
};