// LEETCODE 1646

/*
class Solution {
public:
    
    int getMaximumGenerated(int n) {
        vector<int> dp(n+1, -1);
        if(n == 0 || n == 1) return n;
        dp[0] = 0;
        dp[1] = 1;
        int mx = -1;

        for(int i = 2;i <= n;i++){
            dp[i] = (i%2==0) ? dp[i/2] : (dp[i/2] + dp[i/2 + 1]);
            mx = max(mx, dp[i]);
        }
        return mx;
        
        
    }
};
*/