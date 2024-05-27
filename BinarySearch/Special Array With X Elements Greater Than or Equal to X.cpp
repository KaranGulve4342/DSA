// LEETCODE 1608

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getFirstGreaterOrEqual(vector<int>& nums, int val){
        int start = 0;
        int end = nums.size() - 1;

        int index = nums.size();

        while(start <= end){
            int mid = start + (end - start)/2;

            if(nums[mid] >= val){
                index = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }

        return index;

    }
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int N = nums.size();
        for(int i = 1;i <= N;i++){
            int k = getFirstGreaterOrEqual(nums, i);

            if(N - k == i){
                return i;
            }
        }

        return -1;
    }
};