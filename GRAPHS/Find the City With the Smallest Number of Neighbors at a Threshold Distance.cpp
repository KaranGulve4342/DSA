// LEETCODE 1334

class Solution {
public:
    static bool cmp(pair<int, int> &p1, pair<int, int> &p2){
        if(p1.first != p2.first){
            return p1.first < p2.first;
        }
        else return p1.second > p2.second;
    }
    unordered_map<int, list<pair<int, int>>> adj;
    vector<pair<int, int>> ans;
    
    void Dijkstra(int src, int n, int distanceThreshold){
        vector<int> dist(n+1, INT_MAX);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[src] = 0;
        pq.push({0, src});
        while(!pq.empty()){
            int nodeDistance = pq.top().first;
            int topNode = pq.top().second;

            pq.pop();

            for(auto neighbours : adj[topNode]){
                int v = neighbours.first;
                int w = neighbours.second;

                if(nodeDistance + w < dist[v]){
                    dist[v] = nodeDistance + w;
                    pq.push({dist[v], v});
                }
            }
        }
        int count = 0;
        for(int i = 0;i < n;i++){
            if(i != src && dist[i] <= distanceThreshold){
                count++;
            }
        }
        ans.push_back({count, src});
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        for(int i = 0;i < edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        for(int i = 0;i < n;i++){
            Dijkstra(i, n, distanceThreshold);
        }

        sort(ans.begin(), ans.end(), cmp);
        return ans[0].second;
    }
};