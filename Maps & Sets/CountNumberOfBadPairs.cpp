// LEETCODE 2364

/*
class Solution {
public: // ITS BETTER TO COUNT NUMBER OF GOOD PAIRS FIRST
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        long long count = 0;

        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] - i;
        }

        unordered_map<int, int> umap;
        for (int i = 0; i < n; i++) {
            if (umap.find(nums[i]) != umap.end()) {
                count += umap[nums[i]];
                umap[nums[i]]++;
            } else {
                umap[nums[i]] = 1;
            }
        }
        long long total = n*(n-1)/2;

        return total - count;
    }
};

*/