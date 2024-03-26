// LEETCODE 1254


class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || vis[i][j] || grid[i][j] == 1) {
            return;
        }
        vis[i][j] = true;
        dfs(grid, vis, i + 1, j);
        dfs(grid, vis, i - 1, j);
        dfs(grid, vis, i, j + 1);
        dfs(grid, vis, i, j - 1);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        
        // Mark boundary cells as visited temporarily for DFS traversal
        for (int i = 0; i < n; ++i) {
            dfs(grid, vis, i, 0);
            dfs(grid, vis, i, m - 1);
        }
        for (int j = 0; j < m; ++j) {
            dfs(grid, vis, 0, j);
            dfs(grid, vis, n - 1, j);
        }

        // Count closed islands
        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!vis[i][j] && grid[i][j] == 0) {
                    dfs(grid, vis, i, j);
                    ++count;
                }
            }
        }
        return count;
    }
};
