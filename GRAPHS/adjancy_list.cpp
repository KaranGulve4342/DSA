#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

// template <typename T>

class graph {
public:
    unordered_map<int, list<int> > adj;

    void addEdge(int u, int v, bool direction){
        // direction = 0 -> undirected
        // direction = 1 -> directed graph

        // create an edge from u to v
        adj[u].push_back(v);
        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto i : adj){
            cout<<i.first<<"->";
            for(auto j : i.second) {
                cout<<j<<" , ";
            }
            cout<<endl;
        }
    }
};

int main() {
    int n;
    cout<<"Enter the number of nodes"<<endl;
    cin>>n;

    int m;
    cout<<"Enter the number of edges"<<endl;
    cin>>m;

    graph g;

    for(int i = 0;i < m;i++){
        int u, v;
        cin>>u>>v;

        // creating an undirected graph
        g.addEdge(u, v, 0);
    }
    g.printAdjList();

    return 0;
}


/*
#include <bits/stdc++.h>
using namespace std;

vector<list<int> >graph;
int v; // no. of vertices
void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir){
        graph[dest].push_back(src);
    }
}
void display() {
    for(int i = 0;i < graph.size();i++){
        cout<<i<<" -> ";
        for(auto el : graph[i]){
            cout<<el<<", ";
        }
        cout<<endl;
    }
}

int main()
{
    cin>>v;
    graph.resize(v, list<int> ());
    int e;
    cin>>e;
    while(e--){
        int s, d;
        cin>>s>>d;
        add_edge(s, d);
    }
    display();

    return 0;
    
    return 0;
}
*/