// LEETCODE 802

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> InDegree(n);

        for(int i = 0;i < n;i++){
            for(auto node : graph[i]){
                adj[node].push_back(i);
                InDegree[i]++;
            }
        }

        queue<int> q;
        for(int i = 0;i < n;i++){
            if(InDegree[i] == 0){
                q.push(i);
            }
        }

        vector<bool> safe(n);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safe[node] = true;

            for(auto& neighbour : adj[node]){
                InDegree[neighbour]--;
                if(InDegree[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }
        vector<int> ans;
        for(int i = 0;i < n;i++){
            if(safe[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};