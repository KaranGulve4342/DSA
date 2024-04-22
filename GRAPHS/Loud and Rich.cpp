// LEETCODE 851

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();

        vector<int> indegree(n, 0);
        vector<int> ans(n, INT_MAX);
        unordered_map<int, vector<int>>adj(n);
        queue<int> q;

        for(auto rich : richer){
            int u = rich[0];
            int v = rich[1];
            adj[u].push_back(v);

            indegree[v]++;
        }

        for(int i = 0;i < n;i++){
            ans[i] = i;
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(int i : adj[curr]){
                if(ans[i] == INT_MAX || quiet[ans[i]] > quiet[ans[curr]]){
                    ans[i] = ans[curr];
                }


                indegree[i]--;
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
        }

        return ans;
    }
};