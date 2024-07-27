// GFG POTD 27TH JULY 2024

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int solve(string &str, string &rev, int i, int j, vector<vector<int>>& dp){
        if(i == 0 || j == 0){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(str[i-1] == rev[j-1]){
            return dp[i][j] = 1 + solve(str, rev, i-1, j-1, dp);   
        }
        else{
            return dp[i][j] = max(solve(str, rev, i-1, j, dp), solve(str, rev, i, j-1, dp));
        }
    }
    int countMin(string str){
    //complete the function here
        string rev = str;
        int n = str.length();
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        reverse(rev.begin(), rev.end());
        
        return str.length() - solve(str, rev, n, n, dp);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends