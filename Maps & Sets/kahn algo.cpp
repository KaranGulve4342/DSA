#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
    int V;

    vector<vector<int>> adj; // Adjacency list

public:
    Graph(int V) : V(V), adj(V) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    // Kahn's Algorithm for Topological Sorting
    vector<int> topologicalSort() {
        vector<int> inDegree(V, 0);
        for (int u = 0; u < V; ++u) {
            for (int v : adj[u]) {
                inDegree[v]++;
            }
        }

        queue<int> q;
        for (int u = 0; u < V; ++u) {
            if (inDegree[u] == 0) {
                q.push(u);
            }
        }

        vector<int> result;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            result.push_back(u);
            for (int v : adj[u]) {
                if (--inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // Check for cycle
        if (result.size() != V) {
            cout << "Graph contains a cycle!" << endl;
            return vector<int>();
        }

        return result;
    }
};

int main() {
    // Example usage
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(4, 5);
    g.addEdge(3, 5);

    vector<int> sorted = g.topologicalSort();

    if (!sorted.empty()) {
        cout << "Topological Sort Order: ";
        for (int vertex : sorted) {
            cout << vertex << " ";
        }
        cout << endl;
    }

    return 0;
}
