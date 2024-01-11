// Coding Ninjas

// USING BFS
/*
#include<unordered_map>
#include<queue>
#include<list>

bool isCyclicBFS(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int> >&adj){
    unordered_map<int, int> parent;

    parent[src] = -1;
    visited[src] = 1;
    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto neighbour : adj[front]){
            if(visited[neighbour] == true && neighbour != parent[front]){
                return true;
            }
            else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = front;
            }
        }
    }
    return false;
}
string cycleDetection(vector<vector<int> >&edges, int n, int m){
    // create adjacency list
    unordered_map<int, list<int> >adj);
    for(int i = 0;i < m;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // to handle disconnected components
    unordered_map<int, bool> visited;
    for(int i = 0;i < n;i++){
        if(!visited[i]){
            bool ans = isCycleBFS(i, visited, adj);
            if(ans == 1){
                return "YES";
            }
        }
    }
    return "No";
}
*/

// USING DFS

#include<unordered_map>
#include<queue>
#include<list>

bool isCyclicDFS(int node, int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int> > &adj){
    visited[node] = true;

    for(auto neighbour : adj[node]){
        if(!visited[neighbour]){
            bool cycleDetected = isCycleDFS(neighbour, node, visited, adj);
            if(cycleDetected){
                return true;
            }
        }
        else if(neighbour != parent){
            // cycle present
            return true;
        }
    }
    return false;
}
string cycleDetection(vector<vector<int> >& edges, int n, int m){
    // create adjacency list
    unordered_map<int, list<int> >adj;
    for(int i = 0;i < m;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // to handle disconnected components
    unordered_map<int, bool> visited;
    for(int i = 0;i < n;i++){
        if(!visited[i]){
            bool ans = isCyclicDFS(i, -1, visited, adj);
            if(ans == 1){
                return "Yes";
            }
        }
    }
    return "No";
}

/*
// USING BFS

#include<unordered_map>
#include<queue>
#include<list>

bool isCyclicBFS(int src, unordered_map<int, bool>&visited, unordered_map<int, list<int> >&adj){
    unordered_map<int, int> parent;

    parent[src] = -1;
    visited[src] = 1;
    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int front = q.front;
        q.pop();

        for(auto neighbour : adj[front]){
            if(visited[neighbour] == true && neighbour != parent[front]){
                return true;
            }
            else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = front;
            }
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>>&edges, int n, int m){
    // create adjacency list
    unordered_map<int, list<int> > adj;
    for(int i = 0;i < m;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // to handle disconnected components
    unordered_map<int, bool> visited;
    for(int i = 0;i < n;i++){
        if(!visited[i]){
            bool ans = isCyclicBFS(i, visited, adj);
            if(ans == 1){
                return "Yes";
            }
        }
    }
    return "No";
}

// USING DFS
bool isCyclicDFS(int node, int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int> >&adj){
    visited[node] = true;

    for(auto neighbour : adj[node]){
        if(!visited[neighbour]){
            bool cycleDetected = isCyclicDFS(neighbour, node, visited, adj);
            if(cycleDetected != parent){
                // cycle present
                return true;
            }
        }
        else if(neighbour != parent){
            // cycle present
            return true;
        }
    }
    return false;
}
string cycleDetection(vector<vector<int>>&edges, int n, int m){
    // create adjacency list
    unordered_map<int, list<int> > adj;
    for(int i = 0;i < m;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // to handle disconnected components
    unordered_map<int, bool> visited;
    for(int i = 0;i < n;i++){
        if(!visited[i]){
            bool ans = isCyclicDFS(i, visited, adj);
            if(ans == 1){
                return "Yes";
            }
        }
    }
    return "No";
}

*/

// USING BFS

/*
bool detect(int src, vector<int> adj[], int vis[]){
    vis[src] = 1;
    queue<pair<int, int> >q;
    q.push({src, -1});
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto adjacentNode : adj[node]){
            if(!vis[adjacentNode]){
                vis[adjacentNode] = 1;
                q.push({adjacentNode, node});
            }
            else if(parent != adjacentNode){
                return true;
            }
        }
    }
    return false;
}
bool isCycle(int V, vector<int> adj[]){
    int vis[V] = {0};
    for(int i = 0;i < V;i++){
        if(!vis[i]){
            if(detect(i, adj, vis)) return true;
        }
    }
    return false;
}
*/

// USING DFS
/*
class Solution{
private:
    bool dfs(int node, int parent, vector<int> vis[], vector<int> adj[]){
        vis[node] = 1;
        for(auto adjacentNode : adj[Node]){
            if(!vis[adjacentNode]){
                if(dfs(adjacentNode, node, vis, adj) == true){
                    return true;
                }
            }
            else if(adjacentNode != parent) return true;
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[]){
        int vis[V] = {0};
        for(int i = 0;i < V;i++){
            if(!vis[i]){
                if(dfs(i, -1, vis, adj) == true) return true;
            }
        }
        return false;
    }
};
*/