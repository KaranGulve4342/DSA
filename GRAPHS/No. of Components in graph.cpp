#include <bits/stdc++.h>
using namespace std;

// Define a constant 'N' representing the maximum number of vertices in the graph + 10
const int N = 1e5 + 10;

// Initialize an array 'vis' to keep track of visited vertices and a vector 'g' to represent the graph
bool vis[N];
vector<int> g[N];
vector<vector<int>> cc; // connected components
vector<int> current_cc; // current connected components

// Define a DFS (Depth-First Search) function to explore the connected components of the graph
void dfs(int vertex)
{
    // Mark the current vertex as visited
    vis[vertex] = true;
    current_cc.push_back(vertex);

    // Loop through the child vertices of the current vertex
    for (int child : g[vertex])
    {
        // If a child vertex is already visited, continue to the next child vertex
        if (vis[child])
            continue;

        // Recursively call the DFS function for the child vertex
        dfs(child);
    }
}

int main()
{
    // Read the number of vertices 'n' and edges 'e' from the input stream
    int n, e;
    cin >> n >> e;

    // Populate the graph using the input edges
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;

        // Add an undirected edge between vertices 'x' and 'y'
        g[x].push_back(y);
        g[y].push_back(x);
    }

    // Initialize the count of connected components to 0
    int count = 0;

    // Loop through the vertices to find the number of connected components
    for (int i = 1; i <= n; i++)
    {
        // If a vertex is not visited yet, increment the connected component count and perform a DFS
        if (vis[i])
            continue;
        current_cc.clear();
        dfs(i);
        cc.push_back(current_cc);
        count++;
    }

    // Print the number of connected components
    cout << "The number of connected components is: " << count << endl;
    for (auto c : cc)
    {
        cout << "{";
        for (int v : c)
        {
            cout << v << ",";
        }
        cout << "}" << endl;
    }

    return 0;
} 