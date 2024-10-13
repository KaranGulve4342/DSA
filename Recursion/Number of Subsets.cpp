#include<bits/stdc++.h>
using namespace std;


// using recursion
/*
int solve(int idx, int target, vector<int>& nums){
    if(sum == 0){
        return 1;
    }

    if(idx == 0){
        return nums[0] == target;
    }

    int notTake = solve(idx - 1, target, nums);

    int take = 0;

    if(nums[idx] <= target){
        take = solve(idx - 1, target - nums[idx], nums);
    }

    return take + notTake;
}

int findWays(vector<int>& nums, int target){
    int n = nums.size();

    return solve(n-1, target, nums);
}
*/

// USING MEMOISATION
/*
int solve(int idx, int target, vector<int>& nums, vector<vector<int>>& dp){
    if(target == 0){
        return 1;
    }

    if(idx == 0){
        return nums[0] == target;
    }

    if(dp[idx][target] != -1){
        return dp[idx][target];
    }

    int notTake = solve(idx - 1, target, nums, dp);

    int take = 0;

    if(nums[idx] <= target){
        take = solve(idx - 1, target, nums, dp);
    }

    return dp[idx][target] = notTake + take;
}
int findWays(vector<int>& nums, int target){
    int n = nums.size();

    vector<vector<int>> dp(n, vector<int>(target + 1, -1));

    return solve(n-1, target, nums, dp);
}

*/

// USING TABULATION

int findWays(vector<int>& nums, int target){
    int n = nums.size();

    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    for(int i = 0;i < n;i++){
        dp[i][0] = 1;
    }

    if(nums[0] <= target){
        dp[0][nums[0]] = 1;
    }

    for(int idx = 1;idx < n;idx++){
        for(int sum = 0;sum <= target;sum++){
            int notTake = dp[idx - 1][sum];

            int take = 0;

            if(nums[idx] <= sum){
                take = dp[idx - 1][sum - nums[idx]];
            }

            dp[idx][sum] = notTake + take;
        }
    }

    return dp[n-1][target];
}