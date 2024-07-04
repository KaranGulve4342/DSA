// GFG PRACTICE

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int perfectSum(int nums[], int n, int sum){
        // int count = 0;
        // int subsetCount = 1 << n;
        // for(int mask = 0;mask < subsetCount;mask++){
        //     vector<int> subset;
        //     int temp = 0;
        //     for(int i = 0;i < n;i++){
        //         if(mask & (1 << i)){
        //             subset.push_back(nums[i]);
        //             temp += nums[i];
        //         }
        //     }
        //     if(temp == sum){
        //         count++;
        //     }
        // }
        
        // return count;
        
        const int MOD = 1e9+7;
        
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

        // There's one way to make sum 0 (choose no elements)
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        // Fill the dp table
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                // If we don't include nums[i-1]
                dp[i][j] = dp[i-1][j];

                // If we include nums[i-1]
                if (j >= nums[i-1]) {
                    dp[i][j] = (dp[i][j] + dp[i-1][j-nums[i-1]])%MOD;
                }
            }
        }

        return dp[n][sum] % MOD;
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends