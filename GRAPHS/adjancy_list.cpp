#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

// This class represents a graph using an adjacency list representation.
class graph{
public:
    // The graph is represented using an unordered_map of lists.
    // The key of the map is the vertex, and the value is a list of adjacent vertices.
    unordered_map<int, list<int> > adj;

    // This function is used to add an edge to the graph.
    // The edge is added from vertex 'u' to vertex 'v'.
    // If the graph is undirected, an edge is added from 'v' to 'u' as well.
    void addEdge(int u, int v, bool direction){
        // Add 'v' to the list of vertices adjacent to 'u'.
        adj[u].push_back(v);
        if(direction == 0){ // If the graph is undirected,
            // add 'u' to the list of vertices adjacent to 'v'.
            adj[v].push_back(u);
        }
    }

    // This function is used to print the adjacency list representation of the graph.
    void printAdjList(){
        for(auto i : adj){
            cout<<i.first<<" -> ";
            for(auto j : i.second){
                cout<<j<<" , ";
            }
            cout<<endl;
        }
    }
};

int main(){
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

        // adding an undirected edge between 'u' and 'v'.
        g.addEdge(u, v, 0);
    }
    g.printAdjList();

    return 0;
}