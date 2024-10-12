#include<bits/stdc++.h>
using namespace std;

// Recursion
/*
bool solve(int idx, int k, vector<int>& arr){
    if(target == 0){
        return true;
    }

    if(idx == 0){
        return (arr[0] == target);
    }

    bool notTake = solve(idx - 1, target, arr);
    bool take = false;

    if(arr[idx] <= target){
        take = solve(idx - 1, target - arr[idx], arr);
    }

    return take | notTake;
}

bool subsetSumToK(int n, int k, vector<int>& arr){
    return solve(n-1, k, arr);
}
*/

// Memoisation

/*
bool solve(int idx, int target, vector<int>& arr, vector<vector<int>>& dp){
    if(target == 0){
        return true;
    }

    if(idx == 0){
        return arr[0] == target;
    }

    if(dp[idx][target] != -1){
        return dp[idx][target];
    }

    bool notTake = solve(idx - 1, target, arr, dp);
    bool take = false;

    if(arr[idx] <= target){
        take = solve(idx - 1, target - arr[idx], arr, dp);
    }

    return dp[idx][target] = take | notTake;
}

bool subsetSumToK(int n, int k, vector<int>& arr){
    vector<vector<int>> dp(n, vector<int>(k+1, -1));

    return solve(n-1, k, arr, dp);
}
*/


// Tabulation

bool subsetSumToK(int n, int k, vector<int>& arr){
    vector<vector<bool>> dp(n, vector<bool>(k+1, false));

    for(int i = 0;i < n;i++){
        dp[i][0] = true;
    }

    dp[0][arr[0]] = true;

    for(int idx = 1;idx < n;idx++){
        for(int target = 1;target <= k;target++){
            bool notTake = dp[idx - 1][target];

            bool take = false;

            if(arr[idx] <= target){
                take = dp[idx - 1][target - arr[idx]];
            }

            dp[idx][target] = take | notTake;
        }
    }

    return dp[n-1][k];
}