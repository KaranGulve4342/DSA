// LEETCODE 512

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const long long MOD = 1e9 + 7;
    
    int solve(int n, int A, int L, vector<vector<vector<long long>>> &dp) {
        if(A >= 2 || L >= 3) {
            return 0;
        }

        if(n == 0) {
            return 1;
        }

        if(dp[n][A][L] != -1) {
            return dp[n][A][L];
        }

        long long pSelected = solve(n-1, A, 0, dp) % MOD;
        long long aSelected = solve(n-1, A+1, 0, dp) % MOD;
        long long lSelected = solve(n-1, A, L+1, dp) % MOD;

        return dp[n][A][L] = (pSelected + aSelected + lSelected) % MOD;
    }
    
    int checkRecord(int n) {
        vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(2, vector<long long>(3, -1)));
        return solve(n, 0, 0, dp);
    }
};
