// GFG POTD 13TH JUNE 2024

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int padovanSequence(int n)
    {
        const int MOD = 1e9 + 7;
        if (n == 0 || n == 1 || n == 2) {
            return 1;
        }
        
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = dp[2] = 1;
        
        for (int i = 3; i <= n; i++) {
            dp[i] = (dp[i-2] + dp[i-3]) % MOD;
        }
        
        return dp[n];
    }
    
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout<<ob.padovanSequence(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends