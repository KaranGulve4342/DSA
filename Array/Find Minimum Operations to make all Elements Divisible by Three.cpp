// LEETCODE 3190

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0;i < n;i++){
            ans += (nums[i]%3 > 0);
        }

        return ans;
    }
};