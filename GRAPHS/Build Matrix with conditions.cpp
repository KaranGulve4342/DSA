// LEETCODE 2392

class Solution {
public:
    void fillTopoArray(int k, vector<int>& topo){
        unordered_set<int> vis(topo.begin(), topo.end());
        for(int ele = 1; ele <= k; ele++){
            if(vis.find(ele) == vis.end()){
                topo.push_back(ele);
            }
        }
    }

    vector<int> toposort(int k, vector<vector<int>>& graph){
        vector<int> indegree(k+1, 0);

        for(int node = 1; node <= k; node++){
            for(auto child : graph[node]){
                indegree[child]++;
            }
        }

        queue<int> q;
        for(int node = 1; node <= k; node++){
            if(indegree[node] == 0){
                q.push(node);
            }
        }

        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(auto neighbour : graph[node]){
                indegree[neighbour]--;
                if(indegree[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }

        // Check if there is a cycle
        for(int node = 1; node <= k; node++){
            if(indegree[node] != 0){
                return {};
            }
        }

        return ans;
    }

    vector<vector<int>> buildGraph(int k, vector<vector<int>>& conditions){
        vector<vector<int>> graph(k + 1);
        for(auto condition : conditions){
            int u = condition[0];
            int v = condition[1];
            graph[u].push_back(v);
        }
        return graph;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> rowGraph = buildGraph(k, rowConditions);
        vector<vector<int>> colGraph = buildGraph(k, colConditions);

        vector<int> rowToposort = toposort(k, rowGraph);
        vector<int> colToposort = toposort(k, colGraph);

        // If either toposort is empty, return an empty matrix
        if(rowToposort.size() != k || colToposort.size() != k){
            return {};
        }

        unordered_map<int, int> colIdx;
        for(int j = 0; j < k; j++){
            colIdx[colToposort[j]] = j;
        }

        vector<vector<int>> ans(k, vector<int>(k, 0));
        for(int i = 0; i < k; i++){
            ans[i][colIdx[rowToposort[i]]] = rowToposort[i];
        }

        return ans;
    }
};