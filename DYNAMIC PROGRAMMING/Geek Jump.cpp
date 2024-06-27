// GFG

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(vector<int>& height, int n, int curr, vector<int>& dp){
        if(curr == n-1){
            return 0;
        }
        
        if(dp[curr] != -1){
            return dp[curr];
        }
        
        int minEnergy = INT_MAX;
        
        if(curr + 1 < n){
            int energyNext = abs(height[curr] - height[curr + 1]) + solve(height, n, curr + 1, dp);
            minEnergy = min(minEnergy, energyNext);
        }
        
        if(curr + 2 < n){
            int energyNext = abs(height[curr] - height[curr + 2]) + solve(height, n, curr + 2, dp);
            minEnergy = min(minEnergy, energyNext);
        }
        
        dp[curr] = minEnergy;
        return minEnergy;
    }
    int minimumEnergy(vector<int>& height, int n) {
        vector<int> dp(n, -1);
        
        return solve(height, n, 0, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends