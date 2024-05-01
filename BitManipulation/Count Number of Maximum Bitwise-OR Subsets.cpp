// LEETCODE 2044

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int currIdx, vector<int>& nums, int &maxOR, int currOR, int &ans){
        if(currIdx == nums.size()){
            if(currOR == maxOR){
                ans++;
            }
            return;
        }

        solve(currIdx + 1, nums, maxOR, currOR, ans);
        solve(currIdx + 1, nums, maxOR, currOR | nums[currIdx], ans);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR = 0;
        int ans = 0;

        for(auto num : nums){
            maxOR |= num;
        }

        solve(0, nums, maxOR, 0, ans);
        return ans;
    }
};