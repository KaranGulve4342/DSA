// LEETCODE 2461


class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long n = nums.size();
        long long maxSum = 0;
        
        unordered_map<int, int> umap;
        long long currSum = 0;
        int i = 0;
        while(i < k && i < n){
            umap[nums[i]]++;
            currSum += nums[i];
            i++;
        }

        if(umap.size() == k){
            maxSum = currSum;
        }

        while(i < n){
            umap[nums[i]]++;
            umap[nums[i-k]]--;

            if(umap[nums[i-k]] == 0){
                umap.erase(nums[i-k]);
            }

            currSum += nums[i];
            currSum -= nums[i-k];

            if(umap.size() == k){
                maxSum = max(maxSum, currSum);
            }

            i++;
        }

        return maxSum;
    }
};