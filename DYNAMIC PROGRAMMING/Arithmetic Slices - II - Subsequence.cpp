// LEETCODE 446

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        vector<unordered_map<long long, int>> dp(n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long long diff = (long long)nums[i] - nums[j];
                dp[i][diff] += dp[j].count(diff) ? dp[j][diff] + 1 : 1;
                total += dp[j].count(diff) ? dp[j][diff] : 0;
            }
        }

        return total;
    }
};