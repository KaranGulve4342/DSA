// LEETCODE 2370

class Solution {
public:
    int solve(int idx, string &s, int prev, int k, vector<vector<int>>& dp){
        if(idx == -1){
            return 0;
        }

        if(dp[idx][prev] != -1){
            return dp[idx][prev];
        }

        int take = 0;
        int ch = s[idx] - 'a' + 1;

        if(prev == 0 || abs(ch - prev) <= k){
            take = solve(idx - 1, s, ch, k, dp) + 1;
        }
        int notTake = solve(idx - 1, s, prev, k, dp);
        return dp[idx][prev] = max(take, notTake);
    }
    int longestIdealString(string s, int k) {
        int n = s.length();

        vector<vector<int>> dp(n, vector<int>(27, -1));

        return solve(n-1, s, 0, k, dp);
    }
};