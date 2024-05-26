// LEETCODE 3162

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int count = 0;
        int m = nums1.size();
        int n = nums2.size();

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(nums1[i]%(nums2[j]*k) == 0){
                    count++;
                }
            }
        }

        return count;
    }
};