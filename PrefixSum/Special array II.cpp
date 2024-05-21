// LEETCODE 3152

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> ans(queries.size(), false);
        vector<int> prefix(nums.size());

        // Initialize the first element of prefix
        prefix[0] = 0;

        // Compute the prefix array
        for(int i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i - 1];
            if(nums[i - 1] % 2 == nums[i] % 2) {
                prefix[i]++;
            }
        }

        // Process each query
        for(int i = 0; i < queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int count = prefix[r] - prefix[l];
            ans[i] = (count == 0);
        }

        return ans;
    }
};