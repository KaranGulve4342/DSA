// LEETCODE 18

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> st;
        vector<vector<int>> ans;

        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i = 0;i < n-3;i++){
            for(int j = i+1;j < n-2;j++){
                long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j];

                int lo = j+1;
                int hi = n-1;

                while(lo < hi){
                    if(nums[lo] + nums[hi] < newTarget){
                        lo++;
                    }
                    else if(nums[lo] + nums[hi] > newTarget){
                        hi--;
                    }
                    else{
                        st.insert({nums[i], nums[j], nums[lo], nums[hi]});
                        lo++;
                        hi--;
                    }
                }
            }
        }

        for(auto x : st){
            ans.push_back(x);
        }

        return ans;
    }
};