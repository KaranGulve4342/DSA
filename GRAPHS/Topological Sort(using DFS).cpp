#include<unordered_map>
#include<list>
#include<stack>

void topoSort(int node, vector<bool> &visited, stack<int> &s, unordered_map<int, list<int> > &adj){
    visited[node] = 1;

    for(auto neighbour : adj[node]){
        if(!visited[neighbour]){
            topoSort(neighbour, visited, s, adj);
        }
    }

    s.push(node);
}
vector<int> topologicalSort(vector<vector<int> >&edges, int v, int e){
    // create adj list
    unordered_map<int, list<int> >adj;
    for(int i = 0;i < e;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    vector<bool> visited(v);
    stack<int> s;
    for(int i = 0;i < v;i++){
        if(!visited[i]){
            topoSort(i, visited, s, adj);
        }
    }

    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

/*
#include<unordered_map>
#include<list>
#include<stack>

void topoSort(int node, vector<bool> &visited, stack<int> &s, unordered_map<int, list<int> >&adj){
    visited[node] = 1;
    
    for(auto neighbour : adj[node]){
        if(!visited[neighbour]){
            topoSort(neighbour, visited, s adj);
        }
    }
    s.push(node);
}
vector<int> topologicalSort(vector<vector<int> >&edges, int v, int e){
    // create adj list
    unordered_map<int, list<int> >adj;
    for(int i = 0;i < e;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // call DFS topological Sort util function for all Components
    vector<bool> visited(v);
    stack<int> s;
    for(int i = 0;i < v;i++){
        if(!visited[i]){
            topoSort(i, visited, s, adj);
        }
    }

    vector<int> ans;

    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}
*/

// GFG
/*
class Solution {
    void dfs(int node, int vis[], stack<int> &st, vector<int> adj[]){
        vis[node] = 1;

        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, vis, st, adj);
            }
        }
        st.push(node);
    }

    vector<int> topoSort(int V, vector<int> adj[]){
        int vis[V] = 0;
        stack<int> st;
        for(int i = 0;i < V;i++){
            if(!vis[i]){
                dfs(i, vis, st, adj);
            }
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
}
*/