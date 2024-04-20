// LEETCODE 2192

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj(n);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }

        vector<int> indegree(n, 0);
        for(auto node : adj){
            for(int v : node.second) {
                indegree[v]++;
            }
        }
        for(int i = 0;i < n;i++){
            cout<<indegree[i]<<" ";
        }
        
        queue<int> q;

        for(int i = 0;i < n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        set<int> st[n];
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto it : adj[curr]){
                st[it].insert(curr);

                for(auto itr : st[curr]){
                    st[it].insert(itr);
                }

                indegree[it]--;

                if(indegree[it] == 0){
                    q.push(it);
                }
            }

        }

        vector<vector<int>> ans(n, vector<int>{});

        for(int i = 0;i < n;i++){
            ans[i] = vector<int>(st[i].begin(), st[i].end());
        }
        return ans;
    }
};