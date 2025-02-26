// LEETCODE 1749

class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            int minPrefixSum = 0;
            int maxPrefixSum = 0;
    
            int prefixSum = 0;
    
            for(int i = 0;i < nums.size();i++){
                prefixSum += nums[i];
    
                minPrefixSum = min(minPrefixSum, prefixSum);
    
                maxPrefixSum = max(maxPrefixSum, prefixSum);
            }
    
            return maxPrefixSum - minPrefixSum;
        }
    };