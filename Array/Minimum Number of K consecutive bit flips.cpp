// LEETCODE 995

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> flipped(n, 0);
        int flip = 0; // Keeps track of the number of flips made
        int ans = 0;  // Result to store the minimum number of flips

        for (int i = 0; i < n; ++i) {
            // Check if the current index needs a flip
            if (i >= k) {
                flip ^= flipped[i - k];
            }
            
            if (flip % 2 == nums[i]) {
                // If it needs a flip, but it's not possible (out of bounds)
                if (i + k > n) {
                    return -1;
                }
                // Flip it and mark the flip in the difference array
                flip ^= 1;
                flipped[i] = 1;
                ans++;
            }
        }

        return ans;
    }
};