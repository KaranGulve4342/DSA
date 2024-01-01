// LEETCODE 1269

/*
class Solution {
public:
    vector<vector<int>> memo;
    int MOD = 1000000007;
    int len;
    int dp(int pos, int steps){
        if(steps == 0){
            if(pos == 0) return 1;
            return 0;
        }
        if(memo[pos][steps] != -1){
            return memo[pos][steps];
        }
        int ways = dp(pos, steps-1);
        if(pos > 0){
            ways = (ways + dp(pos - 1, steps - 1)) % MOD;
        }
        if(pos < len - 1){
            ways = (ways + dp(pos + 1, steps - 1)) % MOD;
        }

        return memo[pos][steps] = ways % MOD;
    }
    int numWays(int steps, int arrLen) {
        len = min(steps, arrLen);
        memo = vector(len, vector(steps + 1 , -1));
        return dp(0, steps);
    }
};
*/