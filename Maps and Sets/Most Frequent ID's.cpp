// LEETCODE 3092

class Solution{
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq){
        priority_queue<pair<long long>> pq;
        unordered_map<long long, long long> mp;

        vector<long long> ans;

        for(int i = 0;i < nums.size();i++){
            mp[nums[i]] += freq[i];
            pq.push({mp[nums[i]]m nums[i]});
            while(!pq.empty()){
                pair<long long, long long> p = pq.top();
                if(mp[p.second] != p.first){
                    pq.pop();
                }
                else{
                    break;
                }
            }
            ans.push_back(pq.top().first);
        }
        return ans;
    }
}




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