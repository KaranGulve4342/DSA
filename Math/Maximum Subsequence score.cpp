// LEETCODE 2542

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<long long, long long>> arr;
        for(int i = 0;i < nums2.size();i++){
            arr.push_back({nums2[i], nums1[i]});
        }

        sort(arr.begin(), arr.end());
        reverse(arr.begin(), arr.end());
        long long sum = 0;
        long long result = LLONG_MIN;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(auto &[n1, n2] : arr){
            pq.push(n2);
            sum += n2;

            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }

            if(pq.size() == k){
                result = max(result, sum * n1);
            }
        }
        return result;

    }

};