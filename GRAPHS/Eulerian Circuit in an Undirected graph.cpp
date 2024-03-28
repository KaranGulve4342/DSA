// GFG POTD 29TH MARCH 2024

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isEularCircuitExist(int v, vector<int> adj[]) {
        // Array to store degrees of vertices
        vector<int> degree(v, 0);
        
        // Calculate degree of each vertex
        for (int i = 0; i < v; ++i)
            degree[i] = adj[i].size();

        // Check if all degrees are even
        for (int i = 0; i < v; ++i)
            if (degree[i] % 2 != 0)
                return false; // Eulerian circuit not possible

        // Check if the graph is connected
        vector<bool> visited(v, false);
        dfs(adj, 0, visited); // Start DFS from any vertex
        for (int i = 0; i < v; ++i)
            if (!visited[i] && degree[i] > 0)
                return false; // Graph is not connected

        // If all conditions are satisfied, Eulerian circuit exists
        return true;
    }

    // Depth First Search to check connectivity
    void dfs(vector<int> adj[], int src, vector<bool>& visited) {
        visited[src] = true;
        for (int neighbor : adj[src]) {
            if (!visited[neighbor])
                dfs(adj, neighbor, visited);
        }
    }

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isEularCircuitExist(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends