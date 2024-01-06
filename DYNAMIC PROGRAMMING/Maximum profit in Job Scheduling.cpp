// LEETCODE 1235


class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n);
        for (int i = 0; i < n; ++i) {
            jobs[i] = {endTime[i], startTime[i], profit[i]};
        }
        sort(jobs.begin(), jobs.end());

        vector<int> dp(n);
        dp[0] = jobs[0][2];

        for (int i = 1; i < n; ++i) {
            int left = 0, right = i;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (jobs[mid][0] <= jobs[i][1]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            int currProfit = jobs[i][2];
            if (left > 0) {
                currProfit += dp[left - 1];
            }
            dp[i] = max(dp[i - 1], currProfit);
        }
        return dp[n - 1];
    }
};