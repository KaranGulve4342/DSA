// GFG PRACTICE

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    void dfs(char node, vector<bool>& vis, unordered_map<char, vector<char>>& adjList){
        vis[node - 'a'] = true;
        for(auto it: adjList[node]) {
            if(!vis[it - 'a']) {
                dfs(it, vis, adjList);
            }
        } 
    }
    int isCircle(int N, vector<string> A)
    {
        // code here
        unordered_map<char, vector<char>> adjList;
        
        vector<bool> vis(26, false);
        
        char start;
        
        for(auto x : A){
            char u = x[0];
            char v = x[x.length() - 1];
            
            adjList[u].push_back(v);
            adjList[v].push_back(u);
            
            start = u;
        }
        
        dfs(start, vis, adjList);
        
        for(auto& x : adjList){
            char node = x.first;
            if(!vis[node - 'a'] && adjList[node].size() > 0){
                return 0;
            }
            
            if(adjList[node].size() % 2 == 1){
                return 0;
            }
        }
        
        return 1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<string> A;
        string s;
        
        for(int i = 0;i < N; i++)
        {
            cin>>s;
            A.push_back(s);
        }
        
        Solution ob;
        cout<<ob.isCircle(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends