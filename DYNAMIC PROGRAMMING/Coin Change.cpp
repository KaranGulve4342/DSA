// LEETCODE 322

class Solution{
public:
    int dp[10010];

    int func(int amount, vector<int>& coins){
        if(amount == 0) return 0;
        if(dp[amount] != -1) return dp[amount];

        int ans = INT_MAX;
        for(int coin : coins){
            if(amount - coin >= 0){
                ans = min(ans + 0LL, func(amount - coin, coins) + 1LL);
            }
        }
        return dp[amount] = ans;
    }
    int coinChange(vector<int>& coins, int amount){
        memset(dp, -1, sizeof(dp));
        int ans = func(amount, coins);
        return ans == INT_MAX > -1 : ans;
    }
};

/*
class Solution {
public:
    int dp[10010];
    int func(int amount, vector<int> &coins) {
        if(amount == 0) return 0;
        if(dp[amount] != -1) return dp[amount];

        int ans = INT_MAX;
        for(int coin : coins){
            if(amount-coin >= 0){
                ans = min(ans + 0LL, func(amount-coin, coins) + 1LL);
            }
            
        }
        return dp[amount];
    }
    int coinChange(vector<int> &coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int ans = func(amount, coins);
        return ans == INT_MAX ? -1 : ans;
    }
}
*/

// GFG
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    long long int solveMem(int index, int sum, int coins[], vector<vector<long long>>& dp) {
        if (sum == 0) return 1;
        if (index < 0 || sum < 0) return 0;

        if (dp[index][sum] != -1) {
            return dp[index][sum];
        }

        long long int ways = 0;
        // Include current coin denomination at index 'index' and reduce the sum
        ways += solveMem(index, sum - coins[index], coins, dp);
        // Exclude the current coin denomination at index 'index'
        ways += solveMem(index - 1, sum, coins, dp);

        return dp[index][sum] = ways;
    }

    long long int count(int coins[], int N, int sum) {
        vector<vector<long long>> dp(N, vector<long long>(sum + 1, -1));
        return solveMem(N - 1, sum, coins, dp);
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends