// LEETCODE 2134

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) k++;
        }
        if (k == 0 || k == 1) return 0;

        int count = 0;
        for (int i = 0; i < k; i++) {
            if (nums[i] == 1) count++;
        }

        int maxi = count;

        for (int i = k; i < n + k; i++) {

            if (nums[i % n] == 1) count++;
            if (nums[(i - k) % n] == 1) count--;

            maxi = max(maxi, count);
        }
        return k - maxi;
    }
};