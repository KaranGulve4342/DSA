// LEETCODE 416

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int> >dp;
    bool f(vector<int> &arr, int i, int k) {
        if(k == 0) return true;
        if(i == arr.size()) return false;
        if(dp[i][k] <= k) {
            // we can include or exclude
            return dp[i][k] = f(arr, i+1, k- arr[i]) || f(arr, i+1, k);
        }
        else{
            // always exclude
            return dp[i][k] = f(arr, i+1, k);
        }
    }
    bool canPartition(vector<int> &nums) {
        int s = 0;
        for(int i = 0;i < nums.size(); i++) s += nums[i];
        if(s%2 != 0) return false;
        dp.clear();
        dp.resize(205, vector<int> (20005, -1));
        return f(nums, 0, s/2);
    }
};

int main()
{
    
    
    return 0;
}
// USING RECURSION
/*
bool solve(int index, int arr[], int N, int target){
    if(index >= N || target < 0) return 0;
    if(target == 0) return 1;

    bool incl = solve(index + 1, arr, N, target - arr[index]);
    bool excl = solve(index + 1, arr, N, target - 0);

    return incl || excl;
}

int equalPartition(int N, int arr[]){
    int total = 0;
    for(int i = 0;i < N;i++){
        total += arr[i];
    }

    if(total%2 != 0){
        return 0;
    }

    int target = total/2;

    return solve(0, arr, N, target);
}
*/

// MEMOISATION
/*
bool solveMem(int index, int arr[], int N, int target, vector<vector<int>>&dp){
    // base case
    if(index >= N){
        return 0;
    }
    if(target < 0){
        return 0;
    }
    if(target == 0){
        return 1;
    }

    if(dp[index][target] != -1){
        return dp[index][target];
    }

    bool incl = solveMem(index + 1, arr, N, target - arr[index], dp);
    bool excl = solveMem(index + 1, arr, N, target - 0, dp);

    return dp[index][target] = incl || excl;
}
int equalPartition(int N, int arr[]){
    int total = 0;
    for(int i = 0;i < N;i++){
        total += arr[i];
    }

    if(total%2 != 0){
        return 0;
    }

    int target = total/2;

    vector<vector<int> >dp(N, vector<int>(target + 1, -1));
    return solveMem(0, arr, N, target, dp);
}
*/

// TABULATION
/*
bool solveTab(int N, int arr[], int total){
    vector<vector<int> >dp(N+1, vector<int>(total + 1, 0));

    for(int i = 0;i <= N;i++){
        dp[i][0] = 1;
    }

    for(int index = N-1;index >= 0;index--){
        for(int target = 0;target <= total/2;target++){
            bool incl = 0;
            if(target - arr[index] >= 0){
                incl = dp[index + 1][target - arr[index]];
            }
            bool excl = dp[index + 1][target - 0];

            dp[index][target] = incl || excl;
        }
    }
    return dp[0][total/2];
}
int equalPartition(int N, int arr[]){
    int total = 0;

    for(int i = 0;i < N;i++){
        total += arr[i];
    }

    if(total & 1){
        return 0;
    }
    int target = total/2;

    return solveTab(N, arr, total);
}
*/

// SPACE OPTIMIZATION
/*
bool solveTabSO(int N, int arr[], int total){
    vector<int> curr(total/2 + 1, 0);
    vector<int> next(total/2 + 1, 0);

    curr[0] = 1;
    next[0] = 1;

    for(int index = N-1;index >= 0;index--){
        for(int target = 0;target <= total/2;target++){
            bool incl = 0;
            if(target - arr[index] >= 0){
                incl = next[target - arr[index]];
            }
            bool excl = next[target - 0];

            curr[target] = incl || excl;
        }
        next = curr;
    }
    return next[total/2];
}
int equalPartition(int N, int arr[]){
    int total = 0;

    for(int i = 0;i < N;i++){
        total += arr[i];
    }

    if(total & 1){
        return 0;
    }
    int target = total/2;

    return solveTabSO(N, arr, total);
}
*/

// RECURSION
/*
bool solve(int index, int arr[], int N, int target){
    if(index >= N){
        return 0;
    }
    if(target < 0){
        return 0;
    }
    if(target == 0){
        return 1;
    }

    bool incl = solve(index + 1, arr, N, target - arr[index]);
    bool excl = solve(index + 1, arr, N, target - 0);

    return incl || excl;
}
int equalPartition(int N, int arr[]){
    int total = 0;
    for(int i = 0;i < N;i++){
        total += arr[i];
    }

    if(total & 1){
        return 0;
    }

    int target = total/2;

    return solve(0, arr, N, target);
}
*/

// RECURSION + MEMOISATION
/*
bool solveMem(int index, int arr[], int N, int target, vector<vector<int> >&dp){
    if(index >= N){
        return 0;
    }
    if(target < 0){
        return 0;
    }
    if(target == 0){
        return 1;
    }
    if(dp[index][target] != -1){
        return dp[index][target];
    }

    bool incl = solveMem(index + 1, arr, N, target - arr[index], dp);
    bool excl = solveMem(index + 1, arr, N, target - 0, dp);

    return dp[index][target] = incl || excl;
}

int equalPartition(int N, int arr[]){
    int total = 0;
    for(int i = 0;i < N;i++){
        total += arr[i];
    }

    if(total & 1){
        return 0;
    }

    int target = total / 2;

    return solveMem(0, arr, N, target);
}
*/