// LEETCODE 239

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> pq;

        vector<int> ans(n-k+1);
        for(int i = 0;i < k;i++){
            pq.push({nums[i], i});
        }

        ans[0] = pq.top().first;
        for(int i = k;i < n;i++){
            while(!pq.empty() && pq.top().second <= (i-k)){
                pq.pop();
            }
            pq.push({nums[i], i});
            ans[i-k+1] = pq.top().first;
        }
        return ans;
    }
};