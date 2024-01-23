// GFG POTD 23 JAN 2024

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        //code here
        vector<int> result;
        vector<int> inDegree(n, 0);
        vector<vector<int>> adjList(n, vector<int>());

        // Create adjacency list and calculate in-degrees
        for (auto pre : prerequisites)
        {
            adjList[pre[1]].push_back(pre[0]);
            inDegree[pre[0]]++;
        }

        // Create a queue for BFS
        queue<int> q;

        // Add nodes with in-degree 0 to the queue
        for (int i = 0; i < n; i++)
        {
            if (inDegree[i] == 0)
                q.push(i);
        }

        // Perform BFS
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            result.push_back(node);

            // Update in-degrees of adjacent nodes
            for (int neighbor : adjList[node])
            {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        // Check if all nodes have been visited
        if (result.size() == n)
            return result;

        // If not all nodes are visited, return an empty array
        return {};
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends