// gfg potd 25 feb 2024

//{ Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    // Complete this function
    // unordered_map<long long int, long long int> dp
    
    long long int count(long long int n) {
        vector<long long int> coins = {3, 5, 10};
        vector<long long int> dp(n+1);
        dp[0] = 1;
        
        for(int i = 0;i < coins.size();i++){
            for(int j = coins[i];j <= n;j++){
                dp[j] = dp[j] + dp[j - coins[i]];
            }
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
		ll n;
		cin>>n;
		Solution obj;
		cout<<obj.count(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends