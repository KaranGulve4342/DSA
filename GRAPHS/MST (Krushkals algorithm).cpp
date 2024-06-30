// GFG

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int, int>>> edges;
        
        for(int i = 0;i < V;i++){
            for(auto &edge : adj[i]){
                int u = i;
                int v = edge[0];
                int w = edge[1];
                
                edges.push_back({w, {u, v}});
            }
        }
        
        sort(edges.begin(), edges.end());
        
        vector<int> parent(V);
        vector<int> rank(V, 0);
        
        for(int i = 0;i < V;i++){
            parent[i] = i;
        }
        
        function<int(int)> find = [&](int u){
            if(parent[u] != u){
                parent[u] = find(parent[u]);
            }
            return parent[u];
        };
        
        auto unionSets = [&](int u, int v){
            int rootU = find(u);
            int rootV = find(v);
            
            if(rootU != rootV){
                if(rank[rootU] > rank[rootV]){
                    parent[rootV] = rootU;
                }
                else if(rank[rootU] < rank[rootV]){
                    parent[rootU] = rootV;
                }
                else{
                    parent[rootV] = rootU;
                    rank[rootU]++;
                }
            }
        };
        
        int mstWeight = 0;
        int edgeUsed = 0;
        
        for(auto &edge : edges){
            int weight = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;
            
            if(find(u) != find(v)){
                mstWeight += weight;
                unionSets(u, v);
                edgeUsed++;
                
                if(edgeUsed == V-1){
                    break;
                }
            }
        }
        
        return mstWeight;
        
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends