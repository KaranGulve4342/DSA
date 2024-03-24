// LEETCODE 3092

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq){
        set<pair<long long, long long>> st;
        map<long long, long> mp;

        int n = nums.size();

        for(int i = 0;i < n;i++){
            if(st.count({mp[nums[i]], nums[i]})){
                st.erase({mp[nums[i]], nums[i]});
            }
            mp[nums[i]] += freq[i];

            st.insert({mp[nums[i]], nums[i]});

            ans.push_back(st.rbegin()->first);
        }
        return ans;
    }
}