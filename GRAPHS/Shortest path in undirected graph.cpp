// Coding Ninjas

#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<pair<int, int> >edges, int n, int m, int s, int t){
    
    // create adjacency list
    unordered_map<int, list<int> >adj;
    for(int i = 0;i < edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // do BFS
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;

    queue<int> q;
    q.push(s);
    parent[s] = -1;
    visited[s] = true;

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto i : adj[front]){
            if(!visited[i]){
                visited[i] = true;
                parent[i] = front;
                q.push(i);
            }
        }
    }

    // Prepare shortest path
    vector<int> ans;
    int currentNode = t;
    ans.push_back(t);

    while(currentNode != s){
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

/*
class Solution{
public:
    vector<int> shortestPath(vector<int>& edges, int N, int M, int src){
        vector<int> adj[N];
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int dist[N];
        for(int i = 0;i < N;i++){
            dist[i] = 1e9;
        }
        dist[src] = 0;

        queue<int> q;
        q.push(src);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : adj[node]){
                if(dist[node] + 1 < dist[it]){
                    dist[it] = 1 + dist[node];
                    q.push(it);
                }
            }
        }

        vector<int> ans(N, -1);
        for(int i = 0;i < N;i++){
            if(dist[i] != 1e9){
                ans[i] = dist[i];
            }
        }

        return ans;
    }
}
*/

/*
class Solution{
public:
    vector<int> shortestPath(vector<vector<int> >&edges, int N, int M, int src){
        vector<int> adj[N];
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int dist[N];
        for(int i = 0;i < N;i++){
            dist[i] = 1e9;
        }
        dist[src] = 0;
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int node = q.front()l
            q.pop();
            for(auto it : adj[node]){
                if(dist[node] + 1 < dist[it]){
                    dist[it] = 1 + dist[node];
                    q.push(it);
                }
            }
        }
        vector<int> ans(N, -1);
        for(int i = 0;i < N;i++){
            if(dist[i] != 1e9){
                ans[i] = dist[i];
            }
        }

        return ans;
    }
}
*/