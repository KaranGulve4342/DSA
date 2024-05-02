// LEETCODE 1829
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> ans(nums.size(), 0);
        int k = pow(2, maximumBit) - 1;
        int XOR = k;
        for(int i = 0;i < nums.size();i++){
            XOR ^= nums[i];
            ans[nums.size() - i - 1] = XOR;
        }
        return ans;
    }
};