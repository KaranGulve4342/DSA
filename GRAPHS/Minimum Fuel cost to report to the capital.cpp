// LEETCODE 2477

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long ans = 0;
    long long dfs(unordered_map<long long, vector<long long>>& adj, int node, vector<int>& visited, int seats){
        visited[node] = 1;
        long long count = 1; 
        
        for(auto neighbour : adj[node]){
            int curr = neighbour;

            if(!visited[curr]){
                count += dfs(adj, curr, visited, seats);
            }
        }

        long long x = count / seats;
        if(count % seats != 0){
            x++;
        }

        if(node != 0) ans += x;

        return count;
    }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;

        unordered_map<long long, vector<long long>> adj(n);

        for(int i = 0;i < n - 1;i++){
            int u = roads[i][0];
            int v = roads[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(n, 0);

        dfs(adj, 0, visited, seats);

        return ans;
    }
};
