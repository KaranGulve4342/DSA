#include<bits/stdc++.h>
using namespace std;

// USING RECURSION
// long solve(int idx, int target, int *a){
//     if(idx == 0){
//         return (target%a[0] == 0);
//     }

//     long notTake = solve(idx - 1, target, a);
//     long take = 0;

//     if(a[idx] <= target){
//         take = solve(idx, target - a[idx], a);
//     }

//     return take + notTake;
// }
// long countWaysToMakeChange(int *denominations, int n, int value){
//     return solve(n-1, value, denominations);
// }

// USING MEMOISATION
long solve(int idx, int target, int *a, vector<vector<int>>& dp){
    if(idx == 0){
        return (target%a[0] == 0);
    }

    if(dp[idx][target] != -1){
        return dp[idx][target];
    }

    long notTake = solve(idx - 1, target, a, dp);
    long take = 0;

    if(a[idx] <= target){
        take = solve(idx, target - a[idx], a, dp);
    }

    return dp[idx][target] = take + notTake;
}
long countWaysToMakeChange(int *denominations, int n, int value){
    vector<vector<int>> dp(n, vector<int>(value + 1, -1));

    return solve(n-1, value, denominations, dp);
}