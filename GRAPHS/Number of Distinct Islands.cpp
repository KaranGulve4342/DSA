//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited, vector<pair<int, int>>& vp, int row0, int col0){
        visited[row][col] = true;
        
        int n = grid.size();
        int m = grid[0].size();
        
        vp.push_back({row - row0, col - col0});
        
        vector<pair<int, int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        
        for(int i = 0;i < 4;i++){
            int newrow = row + dirs[i].first;
            int newcol = col + dirs[i].second;
            
            
            if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && !visited[newrow][newcol] && grid[newrow][newcol] == 1){
                dfs(newrow, newcol, grid, visited, vp, row0, col0);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> visited(n+1, vector<bool>(m+1, false));
        
        set<vector<pair<int, int>>> st;
        
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    vector<pair<int, int>> vp;
                    dfs(i, j, grid, visited, vp, i, j);
                    st.insert(vp);
                }
            }
        }
        
        return st.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends