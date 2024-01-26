// LEETCODE 576

class Solution {
public:
    const int MOD = 1e9+7;
    long long solve(int m, int n, int move, int i, int j, vector<vector<vector<long long> > >&dp){
        if(i < 0 | j < 0 || i >= m || j >= n){
            return 1;
        }

        if(move == 0){
            return 0;
        }        

        if(dp[i][j][move] != -1){
            return dp[i][j][move];
        }

        long long ans = ((solve(m, n, move-1, i+1, j, dp) % MOD) + (solve(m, n, move-1, i, j+1, dp) % MOD) + (solve(m, n, move-1, i-1, j, dp) % MOD) + (solve(m, n, move-1, i, j-1, dp) % MOD)) % MOD;

        return dp[i][j][move] = ans % MOD;

    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<long long>>>dp(m+1, vector<vector<long long> >(n+1, vector<long long>(maxMove+1, -1)));

        return solve(m, n, maxMove, startRow, startColumn, dp);
    }
};