#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
#include<limits.h>
#include "vector"

using namespace std;

class Graph{
public:
    unordered_map<int, list<pair<int, int> > >adj;

    void addEdge(int u, int v, int weight){
        pair<int, int> p = make_pair(v, weight);
        adj[u].push_back(p);
    }

    void printAdj(){
        for(auto i : adj){
            cout<<i.first<<"->";
            for(auto j : i.second){
                cout<<"("<<j.first<<","<<j.second<<"), ";
            }
            cout<<endl;
        }
    }
    void dfs(int node, unordered_map<int, bool> &vis, stack<int> &topo){
        vis[node] = true;

        for(auto neighbour : adj[node]){
            if(!vis[neighbour.first]){
                dfs(neighbour.first, vis, topo);
            }
        }
        topo.push(node);
    }

    void getShortestPath(int src, vector<int>&dist, stack<int> &topo){
        dist[src] = 0;

        while(!topo.empty()){
            int top = topo.top();
            topo.pop();

            if(dist[top] != INT_MAX){
                for(auto i : adj[top]){
                    if(dist[top] + i.second < dist[i.first]){
                        dist[i.first] = dist[top] + i.second;
                    }
                }
            }
        }
    }
};

int main(){
    Graph g;
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 4, -1);
    g.addEdge(2, 4, -2);

    g.printAdj();

    int n = 6;
    // topological sort
    unordered_map<int, bool> visited;
    stack<int> s;
    for(int i = 0;i < n;i++){
        if(!visited[i]){
            g.dfs(i, visited, s);
        }
    }

    return 0;
}

/*
class Solution{
private:
    void topoSort(int node, vector<pair<int, int> >adj[], int vis[], stack<int> &st){
        vis[node] = 1;
        for(auto it : adj[node]){
            int v = it.first;
            if(!vis[V]){
                topoSort(v, adj, vis, st);
            }
        }

        st.push(node);
    }

public:
    vector<int> shortestPath(int N, int M, vector<int> edges[]){
        vector<pair<int, int>> adj[N];
        for(int i = 0;i < M:i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            adj[u].push_back({v, wt});
        }

        // find the topo sort
        int vis[N] = {0};
        stack<int> st;
        for(int i = 0;i < N;i++){
            if(!vis[i]){
                topoSort(i, adj, vis, st);
            }
        }

        vector<int> dis(N);
        for(int i = 0;i < N;i++){
            dist[i] = 1e9:
            dist[0] = 0;
            while(!st.empty()){
                int node = st.top();
                st.pop();

                for(auto it : adj[node]){
                    int v = it.first;
                    int wt = it.second;

                    for(dist[node] + wt < dist[V]){
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }

        return dist;


    }
}
*/