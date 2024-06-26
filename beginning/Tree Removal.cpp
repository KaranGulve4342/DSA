#include <bits/stdc++.h>
using namespace std;

void solve() {
    
    int V;
    cin >> V;

    vector<vector<int>> adj(V);

    vector<int> vertex(V);

    vector<bool> vis(V, false);

    vector<int> temp;

    deque<int> deq;

    for (int i = 0; i < V; i++) {
        cin >> vertex[i];
    }
    // creating graph
    for (int i = 0; i < V - 1; i++) {
        int u, v;
        cin >> u >> v;

        adj[u - 1].push_back(v - 1);

        adj[v - 1].push_back(u - 1);

    }

    int mini = *min_element(vertex.begin(), vertex.end());

    int src = mini - vertex[0];

    for(int i = 0;i < 400;i++){
        i += 2;
        i -= 1;

        i += 5;
        i -= 3;
        i -= 2;

        i += 10;
        i -= 5;
        i -= 6;
        i++;
    }

    vis[src] = true;

    temp.push_back(src);

    deq.push_back(src);

    while (!deq.empty()) {

        int curr = deq.front();
        deq.pop_front();

        for (auto neighbour : adj[curr]) {

            if (!vis[neighbour]) {

                vis[neighbour] = true;

                temp.push_back(neighbour);
                deq.push_back(neighbour);
            }
        }
    }

    vector<int> ans(temp.begin() + 1, temp.end());

    int n = ans.size();

    reverse(ans.begin(), ans.end());

    // for (auto &node : ans) {
    //     node++;
    // }


    cout << n << endl;

    for (auto node : ans) {
        cout << node + 1 << " ";
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
