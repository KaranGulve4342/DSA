// GFG POTD

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countWays(string s1, string s2) {
        // code here
        int n = s1.size();
        int m = s2.size();
        const int MOD = 1e9 + 7;
        
        // Create a 2D dp array initialized to 0
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
        
        // Initialize dp[i][0] to 1 for all i because an empty s2 is a subsequence of any string s1
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 1;
        }
        
        // Fill the dp array
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
                } else {
                    dp[i][j] = dp[i - 1][j] % MOD;
                }
            }
        }
        
        // The answer is in dp[n][m]
        return dp[n][m];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        Solution obj;
        int res = obj.countWays(s1, s2);

        cout << res << endl;
    }
}

// } Driver Code Ends