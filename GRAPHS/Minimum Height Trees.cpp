// LEETCODE 310

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1){
            return vector<int>{0};
        }

        unordered_map<int, vector<int>> adj(n);
        vector<int> degree(n, 0);

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            degree[u]++;
            degree[v]++;
        }

        queue<int> q;
        for(int i = 0;i < n;i++){
            if(degree[i] == 1){
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty()){
            int n = q.size();
            ans.clear();

            while(n--){
                int node = q.front();
                q.pop();

                ans.push_back(node);

                for(auto neighbour : adj[node]){
                    degree[neighbour]--;
                    if(degree[neighbour] == 1){
                        q.push(neighbour);
                    }
                }
            }

        }

        return ans;
    }
};