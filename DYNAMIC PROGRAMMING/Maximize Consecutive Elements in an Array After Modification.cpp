// LEETCODE 3041

class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(1000005, 0);
        int mx = -1;
        for(auto num : nums){
            dp[num + 1] = 1 + dp[num];
            dp[num] = max(dp[num], 1 + dp[num-1]);
        }
        for(int i = 0;i < dp.size();i++){
            mx = max(mx, dp[i]);
        }
        return mx;

    }
};