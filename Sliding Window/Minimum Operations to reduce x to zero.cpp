// LEETCODE 1658

/*
class Solution{
public:
    int minOperations(vector<int>& nums, int x) {
        int target = 0;
        int num = nums.size();
        for(int num : nums) target += num;
        target -= x;

        if(target == 0) return n;

        int maxLen = 0;
        int currentSum = 0;
        int left = 0;

        for(int right = 0;right < n;right++){
            currentSum += nums[right];
            while(left <= right && currentSum > target){
                currentSum -= nums[left];
                left++;
            }
            if(currentSum = target){
                maxLen = max(maxLen , right - left + 1);
            }
        }
        return maxLen ? n - maxLen : -1;
    }
}

*/