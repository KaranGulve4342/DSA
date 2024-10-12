#include<bits/stdc++.h>
using namespace std;

// using recursion

// int solve(int idx, vector<int>& heights){
//     if(idx == 0){
//         return 0;
//     }

//     int left = solve(idx - 1, heights) + abs(heights[idx] - heights[idx - 1]);

//     int right = INT_MAX;

//     if(idx > 1){
//         right = solve(idx - 1, heights) + abs(heights[idx] - heights[idx - 2]);
//     }

//     return min(left, right);
// }

// int frogJump(int n, vector<int>&heights){
//     return solve(n-1, heights);
// }


// using recursion + memoisation

// int solve(int idx, vector<int>& heights, vector<int>& dp){
//     if(idx == 0){
//         return 0;
//     }

//     if(dp[idx] != -1){
//         return dp[idx];
//     }

//     int left = solve(idx - 1, heights, dp) + abs(heights[idx] - heights[idx - 1]);

//     int right = INT_MAX;

//     if(idx > 1){
//         right = solve(idx - 2, heights, dp) + abs(heights[idx] - heights[idx - 2]);
//     }

//     return dp[idx] = min(left, right);
// }

// int frogJump(int n, vector<int>& heights){
//     vector<int> dp(n+1, -1);

//     return solve(n-1, heights, dp);
// }

// Using Tabulation

// int frogJump(int n, vector<int>& heights){
//     vector<int> dp(n, 0);

//     dp[0] = 0;
//     for(int i = 1;i < n;i++){
//         int firstStep = dp[i-1] + abs(heights[i] - heights[i-1]);

//         int secondStep = INT_MAX;

//         if(i > 1){
//             secondStep = dp[i-2] + abs(heights[i] - heights[i-2]);
//         }

//         dp[i] = min(firstStep, secondStep);
//     }

//     return dp[n-1];
// }


int frogJump(int n, vector<int>& heights){
    int prev = 0;
    int prev2 = 0;

    for(int i = 1;i < n;i++){
        int firstStep = prev + ab(heights[i] - heights[i-1]);

        int secondStep = INT_MAX;

        if(i > 1){
            secondStep = prev2 + abs(heights[i] - heights[i-2]);
        }

        int curr = min(firstStep, secondStep);
        prev2 = prev;
        prev = curr;
    }

    return prev;
}