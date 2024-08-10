// GFG PRACTICE

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int n;
	    int solve(int i, int j, string &s, string &t, vector<vector<int>>& dp){
	        if(i >= n || j >= n){
	            return 0;
	        }
	        
	        if(dp[i][j] != -1){
	            return dp[i][j];
	        }
	        int ans = 0;
	        if(s[i] == t[j] && i!=j){
	            ans = 1 + solve(i+1, j+1, s, t, dp);
	        }
	        else{
	            ans = max(solve(i+1, j, s, t, dp), solve(i, j+1, s, t, dp));
	        }
	        
	        return dp[i][j] = ans;
	    }
		int LongestRepeatingSubsequence(string s){
		    // Code here
		    n = s.length();
		    
		    string t = s;
		    
		    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
		    
		    return solve(0, 0, s, t, dp);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends