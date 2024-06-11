// LEETCODE 2104

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long n = nums.size();
        long long ans = 0;

        for(long long i = 0;i < n-1;i++){
            long long maxi = nums[i];
            long long mini = nums[i];
            for(long long j = i+1;j < n;j++){
                maxi = max(maxi, nums[j] + 0LL);
                mini = min(mini, nums[j] + 0LL);

                ans += maxi - mini;
            }
        }

        return ans;
    }
};