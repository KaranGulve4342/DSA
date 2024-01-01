// GFG POTD 31st December 2023

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    
    public:
    int solve(int idx, int sum,int N, int coins[], vector<vector<int> >&dp){
        if(sum > 0 && (sum%20 == 0 || sum % 24 == 0 || sum == 2024)){
            return 1;
        }
        if(idx >= N){
            return 0;
        }
        if(dp[idx][sum] != -1){
            return dp[idx][sum];
        }
        
        return dp[idx][sum] = solve(idx+1, sum + coins[idx] , N,coins, dp) || solve(idx + 1, sum, N, coins, dp);
    }
    int isPossible(int N, int coins[]) {
        vector<vector<int> >dp(N, vector<int>(2025, -1));
        return solve(0,0,N,coins,dp);
    }
        
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int coins[N];
        for(int i=0 ; i<N ; i++)
            cin>>coins[i];

        Solution ob;
        cout << ob.isPossible(N,coins) << endl;
    }
    return 0;
}
// } Driver Code Ends