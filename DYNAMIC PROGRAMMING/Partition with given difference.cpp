// GFG POTD 24TH MAY 2024

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int sum = 0;
        for(int i = 0;i < n;i++){
            sum += arr[i];
        }
 
        if ((sum + d) % 2 != 0 || sum < d) return 0;
        
        int target = (sum + d) / 2;
        
        // Initialize dp array
        vector<int> dp(target + 1, 0);
        dp[0] = 1;  
        
        for (int num : arr) {
            for (int j = target; j >= num; --j) {
                dp[j] = (dp[j] + dp[j - num]) % MOD;
            }
        }
        
        return dp[target];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends