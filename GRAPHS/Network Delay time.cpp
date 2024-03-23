// LEETCODE 743

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, list<pair<int, int>>> adj;
        for(int i = 0;i < times.size();i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];

            adj[u].push_back(make_pair(v, w));
        }

        vector<int> dist(n+1, INT_MAX);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[k] = 0;
        pq.push({0, k});

        while(!pq.empty()){
            int nodeDistance = pq.top().first;
            int topNode = pq.top().second;
            pq.pop();

            for(auto neighbour : adj[topNode]){
                int v = neighbour.first;
                int w = neighbour.second;

                if(nodeDistance + w < dist[v]){
                    dist[v] = nodeDistance + w;
                    pq.push({dist[v], v});
                }
            }
        }
        int maxDelay =  *max_element(dist.begin() + 1, dist.end());
        return maxDelay == INT_MAX ? -1 : maxDelay;
    }
};