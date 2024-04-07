// LEETCODE 3107

class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        int median_idx = n/2;
        int median = nums[median_idx];

        int diff = abs(median - k);

        long long operations = 0;

        if(median < k){
            for(int i = median_idx;i < n;i++){
                if(nums[i] <= k){
                    operations += k - nums[i];
                }
            }
        }
        else if(median > k){
            for(int i = median_idx;i >= 0;i--){
                if(nums[i] >= k){
                    operations += nums[i] - k;
                }
            }
        }
        return operations;
    }
};