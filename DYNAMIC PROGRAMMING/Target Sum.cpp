// LEETCODE 494

class Solution {
public:
    int solve(vector<int>& nums, int target, int currSum, int idx, vector<vector<int>>& dp){
        
        if(idx < 0 && currSum == target){
            return 1;
        }

        if(idx < 0){
            return 0;
        }

        if(dp[idx][currSum + 1000] != -1){
            return dp[idx][currSum + 1000];
        }

        int positive = solve(nums, target, currSum + nums[idx], idx - 1, dp);
        int negative = solve(nums, target, currSum - nums[idx], idx - 1, dp);

        return dp[idx][currSum + 1000] = positive + negative;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<vector<int>> dp(n+1, vector<int>(2001, -1));

        return solve(nums, target, 0, n-1, dp);
    }
};