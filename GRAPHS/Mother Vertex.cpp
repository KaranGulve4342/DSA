// GFG PRACTICE

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    void dfs(int i, vector<int> adj[], vector<int>& vis){
        vis[i] = 1;
        
        for(auto it : adj[i]){
            if(!vis[it]) {
                dfs(it, adj, vis);
            }
        }
    }

    // Function to find a Mother Vertex in the Graph.
    int findMotherVertex(int V, vector<int>adj[])
    {
        vector<int> vis(V, 0);
        int probable = -1;
        
        // Run DFS for all vertices and record the last finished vertex
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i, adj, vis);
                probable = i;
            }
        }
        
        // Check if the last finished vertex (probable mother) can reach all vertices
        vector<int> visited(V, 0);
        dfs(probable, adj, visited);
        
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                return -1;
            }
        }
        
        return probable;
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
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends