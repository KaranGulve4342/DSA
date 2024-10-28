// LEETCODE 2501

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(100001, 0);
        sort(nums.begin(), nums.end());
        int ans = 0;

        for(auto num : nums){
            int root = sqrt(num);

            if(root*root == num){
                dp[num] = 1 + dp[root];
            }
            else{
                dp[num] = 1;
            }

            ans = max(ans, dp[num]);
        }

        return ans<2 ? -1 : ans;
    }
};