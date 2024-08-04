// LEETCODE 3243

class Solution {
public:
    vector<int> distances;
    vector<vector<pair<int, int>>> graph;
    int n;
    void dijkstra(int src){
        distances.clear();
        distances.resize(n, INT_MAX);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, src});

        distances[src] = 0;

        while(!pq.empty()){
            auto x = pq.top();

            auto dist = x.first;
            auto node = x.second;

            if(dist > distances[node]){
                continue;
            }

            pq.pop();

            for(auto neighbour : graph[node]){
                auto v = neighbour.first;
                auto w = neighbour.second;

                if(dist + w < distances[v]){
                    distances[v] = dist + w;

                    pq.push({distances[v], v});
                }
            }
        }
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        this->n = n;

        distances.clear();
        distances.resize(n);

        vector<int> ans;

        graph.clear();
        graph.resize(n);

        for(int i = 0;i < n-1;i++){
            graph[i].push_back({i+1, 1});
        }

        for(auto query : queries){
            auto u = query[0];
            auto v = query[1];

            graph[u].push_back({v, 1});

            dijkstra(0);

            ans.push_back(distances[n-1]);
        }

        return ans;
    }
};