// LEETCODE 786

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:

    typedef pair<double, pair<int, int>> pdpi;

    vector<int> kthSmallestPrimeFraction(vector<int>& a, int k){
        priority_queue<pdpi, vector<pdpi>, greater<pdpi>> pq;
        int n = a.size();
        for(int i = 0;i < n;i++){
            pq.push({(double)a[i]/a[n-1], {i, n-1}});
        }

        for(int i = 0;i < k-1;i++){
            auto val = pq.top();
            pq.pop();

            if(val.second.second - 1 > val.second.first){
                pq.push({(double)a[val.second.first]/a[val.second.second - 1], {val.second.first, val.second.second - 1}});
            }
        }

        return {a[pq.top().second.first], a[pq.top().second.second]};
    }
};