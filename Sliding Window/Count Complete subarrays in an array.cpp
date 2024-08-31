// LEETCODE 2799

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for(auto num : nums){
            st.insert(num);
        }
        unordered_map<int, int> umap;
        int left = 0;
        int right = 0;

        int ans = 0;

        while(right < n){
            umap[nums[right]]++;


            while(left <= right && umap.size() == st.size()){
                umap[nums[left]]--;

                if(umap[nums[left]] == 0){
                    umap.erase(nums[left]);
                }

                ans += (n - right);
                left++;
            }
            right++;
        }

        return ans;
    }
};