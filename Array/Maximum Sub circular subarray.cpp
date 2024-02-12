// LEETCODE 918

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int currMax = 0;
        int currMin = 0;

        int maxSum = nums[0];
        int minSum = nums[0];

        int totalSum = 0;

        for(int i = 0;i < n;i++){
            currMax = max(nums[i], currMax + nums[i]);
            maxSum = max(maxSum, currMax);

            currMin = min(nums[i], currMin + nums[i]);
            minSum = min(minSum, currMin);

            totalSum += nums[i];
        }

        if(totalSum == minSum){
            return maxSum;
        }

        return max(maxSum, totalSum - minSum);
    }
};