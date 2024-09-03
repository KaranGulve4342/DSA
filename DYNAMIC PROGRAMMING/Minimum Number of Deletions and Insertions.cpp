// GFG POTD 3RD SEPT 2024

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int solve(int i, int j, int m, int n, string str1, string str2, vector<vector<int>>& dp){
	    if(i == m || j == n){
	        return 0;
	    }
	    
	    if(dp[i][j] != -1){
	        return dp[i][j];
	    }
	    int ans = 0;
	    if(str1[i] == str2[j]){
	        ans = 1 + solve(i+1, j+1, m, n, str1, str2, dp);
	    }
	    else ans = max(solve(i+1, j, m, n, str1, str2, dp), solve(i, j+1, m, n, str1, str2, dp));
	    
	    return dp[i][j] = ans;
	}
	
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int m = str1.length();
	    int n = str2.length();
	    
	    vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
	    
	    int same = solve(0, 0, m, n, str1, str2, dp);
	    
	    return m+n-2*same;
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends