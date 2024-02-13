// GFG POTD 14 FEB 2024

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
	void dfs(int u, int parent, int &time, vector<int> &low, vector<int> &disc, vector<vector<int>> &result, vector<int> adj[]) {
        disc[u] = low[u] = ++time;

        for (int v : adj[u]) {
            if (v == parent) // Skip the edge to parent
                continue;
            
            if (disc[v] == -1) { // If v is not visited yet
                dfs(v, u, time, low, disc, result, adj);
                low[u] = min(low[u], low[v]);
                
                if (low[v] > disc[u]) // If there's no back edge from v to u or any of its ancestors
                    result.push_back({min(u, v), max(u, v)});
            } else { // If v is visited and not a parent, then it's a back edge
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int v, vector<int> adj[]) {
        vector<int> disc(v, -1); // discovery time of each node
        vector<int> low(v, -1); // lowest discovery time reachable from each node
        vector<vector<int>> result;
        int time = 0;

        for (int i = 0; i < v; ++i) {
            if (disc[i] == -1) // If the node is not visited yet
                dfs(i, -1, time, low, disc, result, adj);
        }

        sort(result.begin(), result.end()); // Sort the result
        return result;
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
        vector<vector<int>>ans = obj.criticalConnections(V, adj);
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
	return 0;
}
// } Driver Code Ends