// GFG PRACTICE 3D DP

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int n, m;
    vector<vector<vector<int>>> dp;
    int maxChoco(int row, int col1, int col2, vector<vector<int>>& grid){
        if(col1 < 0 || col1 >= m || col2 < 0 || col2 >= m){
            return 0;
        }
        
        if(row == n){
            return 0;
        }
        
        if(dp[row][col1][col2] != -1){
            return dp[row][col1][col2];
        }
        
        int ans = grid[row][col1];
        
        if(col1 != col2){
            ans += grid[row][col2];
        }
        
        int maxi = 0;
        
        for(int i = col1 - 1;i <= col1 + 1;i++){
            for(int j = col2 - 1;j <= col2 + 1;j++){
                maxi = max(maxi, maxChoco(row + 1, i, j, grid));
            }
        }
        
        ans += maxi;
        
        return dp[row][col1][col2] = ans;
    }
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        
        this->n = n;
        this->m = m;
        
        dp.resize(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return maxChoco(0, 0, m-1, grid);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends