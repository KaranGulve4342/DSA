// LEETCODE 128

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() <= 1)
            return nums.size();

        sort(nums.begin(), nums.end());

        int maxCount = 1; // Initialize to 1 to consider the case when nums has only one element

        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) { // Handle duplicate numbers
                if (nums[i] == nums[i - 1] + 1) {
                    count++;
                } else {
                    maxCount = max(maxCount, count);
                    count = 1;
                }
            }
        }
        // Update maxCount one more time to handle the case when the longest consecutive sequence ends at the last element
        maxCount = max(maxCount, count);

        return maxCount;
    }
};