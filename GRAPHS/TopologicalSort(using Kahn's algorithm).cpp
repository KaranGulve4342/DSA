// Coding Ninjas
#include<unordered_map>
#include<list>
#include<queue>

vector<int> topologicalSort(vector<vector<int> >&edges, int v, int e){
    // create adj list
    unordered_map<int, list<int> > adj;
    for(int i = 0;i < e;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    // find all integers
    vector<int> indegree(v);
    for(auto i : adj){
        for(auto j : i.second){
            indegree[j]++;
        }
    }

    queue<int> q;
    for(int i = 0;i < v;i++){
        if(indegree[i] == 0){
            q.push(i);
        }

        // do bfs
        vector<int> ans;
        while(!q.empty()){
            int front = q.front();
            q.pop();

            // ans store
            ans.push_back(front);

            // neighbour indegree update
            for(auto neighbour : adj[front]){
                indegree[neighbour]--;
                if(indegree[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }
        return ans;
    }
}

/*
KAHN'S ALGORITHM

// GFG

vector<int> topoSort(int V, vector<int> adj[]){
    int indegree[V] = {0};
    for(int i = 0;i < V;i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }

    queue<int> q;
    for(int i = 0;i < V;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);

        // node is in your topo sort
        // so please remove it from the indegree

        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }
    return topo;
}
*/