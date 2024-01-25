// LEETCODE 973

/*
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int,pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        for(auto it : points){
            int dist = it[0]*it[0] + it[1]*it[1];
            pq.push({dist,{it[0], it[1]}});
        }
        vector<vector<int>> ans;
        while(k--){
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            ans.push_back({row, col});
        }
        return ans;
    }
};
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    typedef pair<int, vector<int> > piv;

    vector<vector<int> > kClosest(vector<vector<int> >& arr, int k){
        priority_queue<piv> pq; // maxHeap

        for(vector<int> v : arr){
            int x = v[0];
            int y = v[1];

            int distance = x*x + y*y;

            pq.push({dist, v});

            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<vector<int> >ans;
        while(pq.size() > 0){
            vector<int> v = pq.top().second;
            ans.push_back(v);
            pq.pop();
        }

        return ans;
    }
}