// GFG PRACTICE

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands
    
    void dfs(int row, int col, vector<vector<char>>& grid){
        // Check if current position is out of bounds or not land
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] != '1'){
            return;
        }
        
        // Mark the current cell as visited
        grid[row][col] = '2';
        
        // Directions array representing the 8 possible directions
        int dRow[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dCol[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        
        // Explore all 8 directions
        for(int i = 0; i < 8; i++){
            int newRow = row + dRow[i];
            int newCol = col + dCol[i];
            dfs(newRow, newCol, grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int count = 0;
        
        
        for(int row = 0;row < grid.size();row++){
            for(int col = 0;col < grid[0].size();col++){
                if(grid[row][col] == '1'){
                    dfs(row, col, grid);
                    count++;
                }
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends