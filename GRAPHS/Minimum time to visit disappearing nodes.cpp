// LEETCODE 3112

class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        unordered_map<int, vector<pair<int, int>>> adjList;
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], length = edge[2];
            adjList[u].push_back({v, length});
            adjList[v].push_back({u, length});
        }
        
        vector<int> result(n, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        
        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();
            
            if (result[node] != -1){
                continue;    
            }
            
            result[node] = time;
   
            if (disappear[node] == time){
                continue;
            }
   
            for (const auto& neighbor : adjList[node]) {
                int nextNode = neighbor.first;
                int edgeLength = neighbor.second;
                int nextTime = time + edgeLength;
 
                if (nextTime < disappear[nextNode]) {
                    pq.push({nextTime, nextNode});
                }
            }
        }
        
        return result;
    }
};