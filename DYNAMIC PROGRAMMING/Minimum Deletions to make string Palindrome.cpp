// GFG PRACTICE

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    long long n;
    long long solve(long long i, long long j, string s, string t, vector<vector<long long>>& dp){
        if(i == n || j == n){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        long long ans = 0;
        
        if(s[i] == t[j]){
            ans = 1 + solve(i+1, j+1, s, t, dp);
        }
        else{
            ans = max(solve(i+1, j, s, t, dp), solve(i, j+1, s, t, dp));
        }
        
        dp[i][j] = ans;
        return ans;
    }
    int minimumNumberOfDeletions(string s) { 
        n = s.length();
        
        string t = s;
        
        reverse(t.begin(), t.end());
        
        vector<vector<long long>> dp(n+1, vector<long long>(n+1, 0));
        
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        // long long k = solve(0, 0, s, t, dp);
        long long k = dp[n][n];
        
        return (int)(n-k);
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends