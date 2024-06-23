// LEETCODE 3192

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int flag = 1;

        int count = 0;
        int n = nums.size();

        for(int i = 0;i < n;i++){
            if(nums[i] != flag){
                flag = 1 - flag;
                count++;
            }
        }

        return count;
    }
};