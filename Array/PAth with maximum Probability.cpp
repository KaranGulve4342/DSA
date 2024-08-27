// LEETCODE 1514

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<int, double>> adjList[n];

        for(int i = 0;i < edges.size();i++){
            auto u = edges[i][0];
            auto v = edges[i][1];

            adjList[u].push_back({v, succProb[i]});
            adjList[v].push_back({u, succProb[i]});
        }

        priority_queue<pair<double, int>> pq;

        pq.push({1.0, start_node});

        vector<double> dist(n, INT_MIN);

        dist[start_node] = 1;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            double distance = it.first;
            int node = it.second;

            for(auto neighbour : adjList[node]){
                int adjNode = neighbour.first;
                double edgeWeight = neighbour.second;

                if(dist[adjNode] < distance*edgeWeight){
                    dist[adjNode] = distance*edgeWeight;

                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        
        if(dist[end_node] == INT_MIN){
            return 0.0;
        }
        else{
            return dist[end_node];
        }
    }
};