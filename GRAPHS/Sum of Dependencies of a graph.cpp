// GFG

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int sumOfDependencies(vector<int> adj[], int V) {
        // code here
        int sum = 0;
        
        vector<int> indegree(V, 0);
        for(int u = 0;u < V;u++){
            for(auto v : adj[u]){
                indegree[v]++;
            }
        }
        
        for(int i = 0;i < V;i++){
            sum += indegree[i];
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<int> v[N];
        for (int i = 0; i < M; i++) {
            cin >> x >> y;
            v[x].push_back(y);
        }
        Solution ob;
        cout << ob.sumOfDependencies(v, N) << "\n";
    }
}
// } Driver Code Ends