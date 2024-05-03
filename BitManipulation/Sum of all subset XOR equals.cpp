// LEETCODE 1863

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ans;
    void solve(vector<int>& nums, int idx, int curr){
        if(idx == nums.size()){
            ans += curr;
            return;
        }

        solve(nums, idx + 1, curr);
        solve(nums, idx + 1, curr ^ nums[idx]);
    }
    int subsetXORSum(vector<int>& nums) {
        ans = 0;

        solve(nums, 0, 0);
        return ans;
    }
};