// LEETCODE 1971

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, list<int>> adj;
        for(int i = 0; i < edges.size(); i++) {
            auto u = edges[i][0];
            auto v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        queue<int> q;
        q.push(source);
        visited[source] = true; 

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == destination) return true;

            for (auto it : adj[node]) {
                if (!visited[it]) {
                    visited[it] = true;
                    q.push(it);
                }
            }
        }
        return false;
    }
};