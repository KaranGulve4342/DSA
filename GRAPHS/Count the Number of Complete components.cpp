// LEETCODE 2685

class Solution {
public:
    void bfs(unordered_map<int, list<int>>& adj, vector<bool>& vis, int& src, int& nodes, int& edges) {
        queue<int> q;
        q.push(src);
        vis[src] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            nodes++;

            for (auto neighbour : adj[node]) {
                edges++;
                if (!vis[neighbour]) {
                    q.push(neighbour);
                    vis[neighbour] = true;
                }
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, list<int>> adj;
        vector<bool> vis(n, false);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int nodes = 0;
                int edges = 0;
                bfs(adj, vis, i, nodes, edges);
                if (edges == nodes * (nodes - 1))
                    ans++;
            }
        }

        return ans;
    }
};
