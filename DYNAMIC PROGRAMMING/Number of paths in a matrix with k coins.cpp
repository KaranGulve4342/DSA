// GFG POTD 10 FEB

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    long long solve(int n, int k, vector<vector<int> >&arr, int i, int j, vector<vector<vector<long long> > >&dp){
        if(i > n || j > n || i < 0 || j < 0 || k < 0) return 0;
        
        if(k == arr[i][j] && i == n-1 && j == n-1) return 1;
        
        if(dp[k][i][j] != -1) return dp[k][i][j];
        
        long long temp1 = solve(n, k-arr[i][j], arr, i+1, j, dp);
        
        long long temp2 = solve(n, k-arr[i][j], arr, i, j+1, dp);
        
        return dp[k][i][j] = temp1 + temp2;
    }
    
    long long numberOfPath(int n, int k, vector<vector<int>> arr){
        
        // Code Here
        vector<vector<vector<long long> > > dp(k+1, vector<vector<long long> > (n+1, vector<long long>(n+1, -1)));
        
        return solve(n, k, arr, 0, 0, dp);
    }
};

//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n+1, vector<int>(n+1, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends