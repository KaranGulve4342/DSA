// LEETCODE 629

class Solution {
public:
    const int MOD = 1e9 + 7;
    int countPairs(int n, int k, vector<vector<int> >&dp){
        if(k == 0){
            return 1;
        }

        if(dp[n][k] != -1){
            return dp[n][k];
        }

        int result = 0;

        for(int i = 1;i <= n;i++){
            if(k >= (i-1)){
                result = (result + countPairs(n-1, k - (i-1), dp) % MOD) % MOD;
            }
        }

        return dp[n][k] = result;
    }
    int kInversePairs(int n, int k) {
        vector<vector<int> >dp(n+1, vector<int>(k+1, -1));

        return countPairs(n, k, dp);
    }
};