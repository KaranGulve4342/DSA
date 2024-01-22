// LEETCODE 152

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = INT_MIN;
        int left = 1;
        int right = 1;
        int n = nums.size();

        for(int i = 0;i < n;i++){
            left *= nums[i];
            right *= nums[n-i-1];
            result = max(result,max(left, right));

            if(left == 0) left = 1;
            if(right == 0) right = 1;
        }

        return result;
    }
};