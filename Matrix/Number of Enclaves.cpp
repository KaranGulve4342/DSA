//  GFG PROBLEM OF THE DAY 29/09/2023

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(vector<vector<int>>&grid, int x, int y){
        int n = grid.size();
        int m = grid[0].size();
        
        if(x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0){
            return;
        }
        grid[x][y] = 0;
        dfs(grid, x + 1, y);
        dfs(grid, x - 1, y);
        dfs(grid, x, y + 1);
        dfs(grid, x, y - 1);
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        if(grid.empty() || grid[0].empty()) return 0;
        
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = 0;i < n;i++){
            if(grid[i][0] == 1){
                dfs(grid , i , 0);
            }
            if(grid[i][m-1] == 1){
                dfs(grid, i, m-1);
            }
        }
        for(int i = 0;i < m;i++){
            if(grid[0][i] == 1){
                dfs(grid, 0, i);
            }
            if(grid[n-1][i] == 1){
                dfs(grid, n-1, i);
            }
        }
        int count = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(grid[i][j] == 1){
                    count++;
                }
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends