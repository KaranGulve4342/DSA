// GFG POTD 3RD JUNE 2024

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int numberOfConsecutiveOnes(int n) {
        const int MOD = 1e9 + 7;

        vector<long long> dp(n + 1, 0);
        dp[1] = 2; // "0", "1"
        dp[2] = 3; // "00", "01", "10"

        for (int i = 3; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
        }

        long long total = 1;
        for (int i = 0; i < n; i++) {
            total = (total * 2) % MOD;
        }

        long long result = (total - dp[n] + MOD) % MOD;

        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.numberOfConsecutiveOnes(N) << endl;
    }
    return 0;
}

// } Driver Code Ends