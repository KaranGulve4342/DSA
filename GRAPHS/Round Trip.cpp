#include<bits/stdc++.h>
using namespace std;

int cycle_start = -1, cycle_end = -1;

bool dfs(int u, int parent, vector<vector<int>>& adjList, vector<int>& parent_track, vector<bool>& visited) {
    visited[u] = true;
    parent_track[u] = parent;

    for (auto neighbour : adjList[u]) {
        if (neighbour == parent) continue;  // Ignore the edge to the parent

        if (visited[neighbour]) {
            cycle_start = neighbour;
            cycle_end = u;
            return true;
        } else {
            if (dfs(neighbour, u, adjList, parent_track, visited)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjList(n + 1);
    vector<bool> visited(n + 1, false);
    vector<int> parent_track(n + 1, -1);

    // Reading input
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Running DFS to find a cycle
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adjList, parent_track, visited)) {
                break;
            }
        }
    }

    if (cycle_start == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        // Reconstructing the cycle
        vector<int> cycle;
        cycle.push_back(cycle_start);

        int curr = cycle_end;
        while (curr != cycle_start) {
            cycle.push_back(curr);
            curr = parent_track[curr];
        }
        cycle.push_back(cycle_start);

        reverse(cycle.begin(), cycle.end());

        cout << cycle.size() << endl;
        for (int city : cycle) {
            cout << city << " ";
        }
        cout << endl;
    }

    return 0;
}
