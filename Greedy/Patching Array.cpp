// LEETCODE 330

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long patches = 0;
        long long count = 1;
        long long i = 0;
        long long sz = nums.size();

        while(count <= n){
            if(i < sz && nums[i] <= count){
                count += nums[i++];
            }
            else{
                count *= 2;
                patches++;
            }
        }

        return patches;
    }
};