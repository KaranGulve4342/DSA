//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    const int MOD = (int)(1e9 + 7);
    int solve(int idx, int target, vector<int>& arr, vector<vector<int>>& dp){
        if(idx == 0){
            if(target == 0 && arr[0] == 0){
                return 2;
            }
            if(target == 0 || target == arr[0]){
                return 1;
            }
            
            return 0;
        }
        
        if(dp[idx][target] != -1){
            return dp[idx][target];
        }
    
        int notTake = solve(idx - 1, target, arr, dp);
        int take = 0;
    
        if(arr[idx] <= target){
            take = solve(idx - 1, target - arr[idx], arr, dp);
        }
    
        return dp[idx][target] = (take + notTake)%MOD;
    }
    int findWays(vector<int>& arr, int target){
        int n = arr.size();
        
        vector<vector<int>> dp(n+1, vector<int>(target + 1, -1));
    
        return solve(n-1, target, arr, dp);
    }
    
    int countPartitions(int n, int d, vector<int>& arr){
        int totalSum = 0;
    
        for(auto it : arr){
            totalSum += it;
        }
    
        if(totalSum-d < 0 || (totalSum-d)&1){
            return false;
        }
    
        return findWays(arr, (totalSum-d)/2);
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