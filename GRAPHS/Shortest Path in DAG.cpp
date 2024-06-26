// GFG

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int, int>> adj[N];
        for(auto edge : edges){
            int v = edge[0];
            int e = edge[1];
            int w = edge[2];
            
            adj[v].push_back({e, w});
        }
        
        vector<int> dist(N, INT_MAX);
        dist[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        
        while(!pq.empty()){
            int node = pq.top().first;
            int currDist = pq.top().second;
            pq.pop();
            
            for(auto neighbour : adj[node]){
                int v = neighbour.first;
                int w = neighbour.second;
                
                if(currDist + w < dist[v]){
                    dist[v] = currDist + w;
                    pq.push({v, dist[v]});
                }
            }
        }
        
        vector<int> ans(N, -1);
        for(int i = 0;i < N;i++){
            if(dist[i] != INT_MAX){
                ans[i] = dist[i];   
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends