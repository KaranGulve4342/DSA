// LEETCODE 3282

class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long n = nums.size();

        long long start = nums[0];

        long long left = 0;

        long long ans = 0;

        for(long long right = 1;right < n-1;right++){
            if(nums[right] > nums[left]){
                ans += start*(right - left)*1LL;

                start = nums[right];
                left = right;
            }
        }

        ans += start*(n-left-1)*1LL;

        return ans;
    }
};