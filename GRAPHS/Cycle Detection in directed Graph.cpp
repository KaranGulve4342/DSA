#include<unordered_map>
#include<list>

bool checkCycleDFS(int node, unordered_map<int, bool> &visited,
unordered_map<int, bool> &dfsVisited, unordered_map<int, list<int> > &adj){
    visited[node] = true;
    dfsVisited[node] = true;

    for(auto neighbour : adj[node]){
        if(!visited[neighbour]){
            bool cycleDetected = checkCycleDFS(neighbour, visited, dfsVisited, adj); 
            if(cycleDetected){
                return true;
            }         
        }
        else if(dfsVisited[neighbour]){
            // visited true
            return true;
        }
    }
    dfsVisited[node] = false;
    return false;

}


int detectCycleInDirectedGraph(int n, vector<pair<int, int> >&graph){
    // crete adj list
    unordered_map<int, list<int> >adj;
    for(int i = 0;i < edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    // call dfs for all components
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    for(int i = 1;i <= n;i++){
        if(!visited[i]){
            bool cycleFound = checkCycle(i, visited, dfsVisited, adj);
            if(cycleFound){
                return true;
            }
        }
    }
    return false;
}

/*
bool checkCycleDFS(int node, unordered_map<int, bool>&visited, unordered_map<int, bool>&dfsVisited, unordered_map<int, list<int> >&adj){
    visited[node] = true;
    dfsVisited[node] = true;

    for(auto neighbour: adj[node]){
        if(!visited[neighbour]){
            bool cycleDetected = checkCycleDFS(neighbour, visited, adj);
            if(cycleDetected){
                return true;
            }
        }
        else if(dfsVisited[neighbour]){
            return true;
        }
    }

    dfsVisited[node] = false;
    return false;
}
int detectCycleInDirectedGraph(int n, vector<pair<int, int>>&edges){
    // create adj list
    unordered_map<int, list<int> >adj;
    for(int i = 0;i < edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    // call dfs for all components
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    for(int i = 1;i <= n;i++){
        if(!visited[i]){
            bool cycleFound = checkCycleDFS(i, visited, dfsVisited, adj){
                if(cycleFound){
                    return true;
                }
            }
        }
    }
    return false;
}
*/


class Solution{
public:
    bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[]){
        vis[node] = 1;
        pathVis[node] = 1;

        // traverse for adjacent nodes
        for(auto it : adj[node]){

            // when the node is not visited
            if(vis[it] == 0){
                if(dfs(it, adj, vis, pathVis) == true){
                    return true;
                }
            }
            // if the node has been previously visited
            // but it has to be visited on the same path
            else if (pathVis[i])
            {
                return true;
            }
        }
        pathVis[node] = 0;
        return false;
    }

    bool isCyclic(int V, vector<int> adj[]){
        int vis[V] = {0};
        int pathVis[V] = {0};

        for(int i = 0;i < V;i++){
            if(vis[i] == 0){
                if(dfsCheck(i, adj, vis, pathVis) == true){
                    return true;
                }
            }
        }
        return false;
    }
}


// USING KAHN'S ALGORITHM
/*

class Solution{
    bool isCyclic(int V, vector<int> adj[]){
        int indegree[V] = {0};
        for(int i = 0;i < V;i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < V;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int count = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;

            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }

        if(count == V) return false;
        return true;
    }
}


*/