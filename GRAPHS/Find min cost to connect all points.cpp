// LEETCODE 1584


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int distance(vector<int>& p1, vector<int>& p2){
        return (abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]));
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        unordered_map<int, vector<pair<int, int>>> graph;

        for(int i = 0;i < n;i++){
            for(int j = i+1;j < n;j++){
                int dist = distance(points[i], points[j]);
                graph[i].emplace_back(j, dist);
                graph[j].emplace_back(i, dist);
            }
        }

        vector<bool> visited(n, false);
        int minCost = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, 0});

        while(!pq.empty()){
            auto x = pq.top();
            pq.pop(); // Remove the top element
            int cost = x.first;
            int node = x.second;

            if(!visited[node]){
                visited[node] = true;
                ans += cost;

                for(const auto& [neighbour, edgeCost] : graph[node]){
                    if(!visited[neighbour]){
                        pq.push({edgeCost, neighbour}); // Push updated cost to reach neighbour
                    }
                }
            }
        }
        return ans;
    }
};