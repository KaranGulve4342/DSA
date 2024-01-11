// LEETCODE 547

class Solution{
    void dfs(int node, vector<int> &adjList, int visited[]){
        visited[node] = 1;
        for(auto it : adjList[node]){
            if(!visited[it]){
                dfs(it, adjList, visited);
            }
        }
    }
    int numProvinces(vector<vector<int> >adj, int V){
        vector<int> adjList[V];

        // to change adj matrix to list
        for(int i = 0;i < V;i++){
            for(int j = 0;j < V;j++){
                if(adj[i][j] == 1 && i!=j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        int visited[V] = {0};
        int count = 0;
        for(int i = 0;i < V;i++){
            if(!visited[i]){
                count++;
                dfs(i, adjList, visited);
            }
        }
        return count;
    }
}