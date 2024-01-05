// GFG POTD 5 Jan 2024

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	#define MOD 1000000007
    #define MAX 100001
    
    long long dp[MAX][2];

    // Recursive function with memoization
    long long countWays(int N, int isBuilding){
        // Base case
        if(N == 1){
            return 1;
        }

        // If already computed, return the value from the memoization array
        if(dp[N][isBuilding] != -1){
            return dp[N][isBuilding];
        }

        long long ways = 0;

        // If building is allowed
        if(isBuilding == 1){
            // Place an empty plot
            ways = (ways + countWays(N - 1, 0)) % MOD;
        }

        // Place a building
        ways = (ways + countWays(N - 1, 1)) % MOD;

        // Memoize the result
        dp[N][isBuilding] = ways;

        return ways;
    }

    int TotalWays(int N){
        // Initialize memoization array with -1
        memset(dp, -1, sizeof(dp));

        // Calculate ways with recursion and memoization
        long long waysBuilding = countWays(N, 1);
        long long waysEmpty = countWays(N, 0);

        // Total ways = (waysBuilding + waysEmpty)^2 % MOD
        long long totalWays = (waysBuilding + waysEmpty) % MOD;
        totalWays = (totalWays * totalWays) % MOD;

        return (int) totalWays;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends