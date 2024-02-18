// GFG CONTEST 18 FEB 2024

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
// User function Template for C++
class Solution
{
public:
    void dfs(int i, vector<int> adj[], bool v[], int c2[], int c3[]){
        v[i] = true;
        for(auto x : adj[i]){
            if(v[x] == false){
                dfs(x, adj, v, c2, c3);
                c2[i] += c2[x];
                c3[i] += c3[x];
            }
        }
    }
    int splittingEdges(int n, vector<int> &values, vector<vector<int>> &edges)
    {
        vector<int> adj[n];
        bool v[n];
        int c2[n], c3[n];
        int i, j, ans = 0, t2 = 0, t3 = 0;
        
        for(i = 0;i < n-1;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        for(i = 0;i < n;i++){
            v[i] = false;
            c2[i] = c3[i] = 0;
        }
        
        for(i = 0;i < n;i++){
            if(values[i] == 2){
                c2[i]++;
                t2++;
            }
            else if(values[i] == 3){
                c3[i]++;
                t3++;
            }
        }
        
        dfs(0, adj, v, c2, c3);
        
        for(i = 1;i < n;i++){
            if(t2 - c2[i] > 0 && t3 - c3[i] > 0 && c2[i] > 0 && c3[i] > 0){
                ans++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--)
    {
        int N;
        scanf("%d",&N);
        
        vector<int> Values(N);
        
        for(int i = 0;i < N; i++)
        {
            cin >> Values[i];
        }
        
        vector<vector<int>> Edges(N-1, vector<int>(2));
        Matrix::input(Edges,N-1,2);
        
        Solution obj;
        int res = obj.splittingEdges(N, Values, Edges);
        
        cout<<res<<endl;
    }
}
// } Driver Code Ends