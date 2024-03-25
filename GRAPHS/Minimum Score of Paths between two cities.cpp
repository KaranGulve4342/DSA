// LEETCODE 2492

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, list<pair<int, int>>> adj;
        for(int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<bool> visited(n + 1, false);
        queue<int> q;
        q.push(1);

        int ans = INT_MAX;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            visited[node] = true;

            for(auto neighbour : adj[node]) {
                if(!visited[neighbour.first]) {
                    q.push(neighbour.first);
                    visited[neighbour.first] = true;
                }
            }
        }
        for(int i = 0;i < roads.size();i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];

            if(visited[u] && visited[v] && w < ans){
                ans = w;
            }
        }
        return ans;
    }
};
