// LEETCODE 658

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    typedef pair<int, int> pi;
    vector<int> findCLosestElements(vector<int>& arr, int k, int x){
        priority_queue<pi> pq; // maxHeap
        
        for(int ele : arr){
            int distance = abs(x - ele);
            pq.push({distance, ele});
            if(pq.size() > k) pq.top();
        }

        vector<int> ans;
        while(pq.size() > 0){
            int ele = pq.top().second;
            ans.push_back(ele);
            pq.pop();
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
/*
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();

        priority_queue<pair<int, int> > pq;
        for(int i = 0;i < n;i++){
            int diff = abs(arr[i] - x);

            pq.push({diff, arr[i]});

            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<int> ans;
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            ans.push_back(p.second);
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
*/