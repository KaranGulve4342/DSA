#include<bits/stdc++.h>
using namespace std;

// USING RECURSION
/*
int solve(int idx, int prev, int arr[], int n){
    if(idx == n){
        return 0;
    }

    int notTake = 0 + solve(idx + 1, prev, arr, n);

    int take = 0;
    if(prev == -1 || arr[idx] > arr[prev]){
        take = 1 + solve(idx + 1, idx, arr, n);
    }

    return max(take, notTake);
}
int longestIncreasingSubsequence(int arr[], int n){
    return solve(0, -1, arr, n);
}
*/

// USING MEMOISATION
// int solve(int idx, int prev, int arr[], int n, vector<vector<int>>& dp){
//     if(idx == n){
//         return 0;
//     }

//     if(dp[idx][prev+1] != -1){
//         return dp[idx][prev + 1];
//     }

//     int notTake = 0 + solve(idx + 1, prev, arr, n, dp);
//     int take = 0;

//     if(prev == -1 || arr[idx] > arr[prev]){
//         take = 1 + solve(idx + 1, idx, arr, n, dp);
//     }

//     return dp[idx][prev + 1] = max(take, notTake);
// }
// int longestIncreasingSubsequence(int arr[], int n){
//     vector<vector<int>> dp(n, vector<int>(n+1, -1));

//     return solve(0, -1, arr, n, dp);
// }


// USING TABULATION
// int longestIncreasingSubsequence(int arr[], int n){
//     vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

//     for(int idx = n-1;idx >= 0;idx--){
//         for(int prev = idx - 1;prev >= -1;prev--){
//             int notTake = 0 + dp[idx + 1][prev + 1];
//             int take = 0;

//             if(prev == -1 || arr[idx] > arr[prev]){
//                 take = 1 + dp[idx + 1][prev + 1];
//             }

//             dp[idx][prev + 1] = max(take, notTake);
//         }
//     }


//     return dp[0][0];
// }


// TABULATION + SPACE OPTIMIZATION

int longestIncreasingSubsequence(int arr[], int n){
    vector<int> dp(n+1, 1);

    int maxi = 1;

    for(int i = 0;i < n;i++){
        for(int prev = 0;prev < i;prev++){
            if(arr[prev] < arr[i]){
                dp[i] = max(dp[i], 1 + dp[prev]);
            }
        }
        maxi = max(maxi, dp[i]);
    }

    return maxi;
}