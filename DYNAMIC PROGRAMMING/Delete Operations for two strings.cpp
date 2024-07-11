// LEETCODE 583

class Solution {
public:
    int minDistance(string s, string t) {
        int n = s.length();
        int m = t.length();

        if(s == t) return 0;
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        int k = 0;

        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    k = max(k, dp[i][j]);
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        if(k == 0){
            return n+m;
        }

        return m+n-(2*k);
    }
};