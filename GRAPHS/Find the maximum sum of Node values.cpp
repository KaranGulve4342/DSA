// LEETCODE 3068

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxSumOfNodes(int idx, int isEven, vector<int>& nums, int k, vector<vector<long long>> &dp){
        if(idx == nums.size()){
            return isEven == 1 ? 0 : INT_MIN;
        }

        if(dp[idx][isEven] != -1){
            return dp[idx][isEven];
        }

        long long noXorDone = nums[idx] + maxSumOfNodes(idx + 1, isEven, nums, k, dp);

        long long XorDone = (nums[idx]^k) + maxSumOfNodes(idx + 1, isEven^1, nums, k, dp);

        return dp[idx][isEven] = max(XorDone, noXorDone);
    }
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        vector<vector<long long>> dp(nums.size(), vector<long long>(2, -1));

        return maxSumOfNodes(0, 1, nums, k, dp);
    }
};