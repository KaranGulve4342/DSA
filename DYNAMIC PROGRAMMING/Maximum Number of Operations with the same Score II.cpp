// LEETCODE 3040

class Solution {
public:
    int solve(int i, int j, int sum, vector<int>& nums, vector<vector<int>>& dp){
        if(i >= j){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans1 = 0;
        int ans2 = 0;
        int ans3 = 0;
        int a = nums[i] + nums[j];
        int b = nums[i] + nums[i+1];
        int c = nums[j] + nums[j-1];

        if(a == sum){
            ans1 = 1 + solve(i+1, j-1, sum ,nums, dp);
        }
        if(b == sum){
            ans2 = 1 + solve(i+2, j, sum, nums, dp);
        }
        if(c == sum){
            ans3 = 1 + solve(i, j-2, sum, nums, dp);
        }

        return dp[i][j] = max({ans1, ans2, ans3});
    }
    int maxOperations(vector<int>& nums) {
        int n = nums.size();

        if(n < 0){
            return 0;
        }

        int sum1 = nums[0] + nums[1];
        int sum2 = nums[0] + nums[n-1];
        int sum3 = nums[n-1] + nums[n-2];

        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<vector<int>> temp(n, vector<int>(n, -1));

        int ans1 = solve(0, n-1, sum1, nums, dp);
        dp = temp;

        int ans2 = solve(0, n-1, sum2, nums, dp);
        dp = temp;

        int ans3 = solve(0, n-1, sum3, nums, dp);
        dp = temp;

        int ans = max({ans1, ans2, ans3});
        return ans;
    }
};