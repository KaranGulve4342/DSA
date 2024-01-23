// GFG POTD 24 JAN 2024


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends
class Solution {
  public:
    void dfs(int s, vector<int>* adj, vector<bool>& vis) {
        vis[s] = true;
        for (int x : adj[s]) {
            if (!vis[x]) {
                dfs(x, adj, vis);
            }
        }
    }
    
    int isTree(int n, int m, vector<vector<int>>& edges) {
        if (n - m != 1) {
            return false;
        }
    
        vector<bool> vis(n, false);
        vector<int>* adj = new vector<int>[n];
    
        for (vector<int>& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
    
        dfs(0, adj, vis);
    
        // Check if all nodes are visited using a simple loop
        for (bool x : vis) {
            if (!x) {
                return false;
            }
        }
    
        return true; // The graph is a tree
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> edges(m, vector<int>(2));
        Matrix::input(edges,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, edges);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends