// GFG POTD 16 JAN 2024

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int m, int n, vector<vector<int> >&dp){
        if(n == 0) return 1;
        
        if(m < n) return 0;
        
        if(dp[m][n] != -1){
            return dp[m][n];
        }
        
        int ans = solve(m/2, n-1, dp) + solve(m-1, n, dp);
        
        return dp[m][n] = ans;
    }
    int numberSequence(int m, int n){

        vector<vector<int> > dp(m+1, vector<int>(n+1, -1));
        return solve(m, n, dp);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends