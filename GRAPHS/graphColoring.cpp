#include <iostream>
#include <vector>
#include <list>
using namespace std;

// Function to add an edge to the graph
void addEdge(vector<list<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); // Graph is undirected
}

// Assigns colors to all vertices
void greedyColoring(vector<list<int>>& adj, int V) {
    vector<int> result(V, -1); // Stores the result (color assigned to vertex)

    result[0] = 0; // Assign the first color to the first vertex

    // Assign colors to the remaining V-1 vertices
    for (int u = 1; u < V; u++) {
        vector<bool> available(V, true); // Array to track available colors for a vertex

        // Process all adjacent vertices and mark their colors as unavailable
        for (auto i : adj[u]) {
            if (result[i] != -1) {
                available[result[i]] = false;
            }
        }

        // Find the first available color
        int cr;
        for (cr = 0; cr < V; cr++) {
            if (available[cr]) {
                break;
            }
        }

        result[u] = cr; // Assign the found color to the current vertex
    }

    // Print the result
    for (int u = 0; u < V; u++) {
        cout << "Vertex " << u << " ---> Color " << result[u] << endl;
    }
}

int main() {
    // Create a graph given in the example
    int V = 5;
    vector<list<int>> adj(V);

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

    cout << "Coloring of the graph using greedy algorithm:\n";
    greedyColoring(adj, V);

    return 0;
}
