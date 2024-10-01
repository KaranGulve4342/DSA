#include <bits/stdc++.h>
using namespace std;

void dfs(int i, unordered_map<int, vector<int>>& adjList, vector<bool>& visited) {
    visited[i] = true;

    for (auto node : adjList[i]) {
        if (!visited[node]) {
            dfs(node, adjList, visited);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<int>> adjList;

    // Input the graph (assuming 1-based indexing for nodes)
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Make sure to account for 1-based indexing, so the visited array needs size (n+1)
    vector<bool> visited(n + 1, false);
    vector<int> leads;

    int components = 0;

    // Loop through all nodes, assuming 1-based indexing
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            leads.push_back(i); // Mark the lead node of the component
            dfs(i, adjList, visited);
            components++;
        }
    }

    // Output the number of new connections needed
    cout << components - 1 << endl;

    // If there are multiple components, connect them
    if (components > 1) {
        for (int i = 1; i < components; i++) {
            cout << leads[i - 1] << " " << leads[i] << endl;
        }
    }

    return 0;
}
