// LEETCODE 1034

class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int currColor, vector<vector<bool>>& vis){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != currColor || vis[i][j]){
            return;
        }

        vis[i][j] = true;
        grid[i][j] = -currColor;
        dfs(grid, i+1, j, currColor, vis);
        dfs(grid, i, j+1, currColor, vis);
        dfs(grid, i-1, j, currColor, vis);
        dfs(grid, i, j-1, currColor, vis);

        if(i > 0 && i < grid.size() - 1 && j > 0 && j < grid[0].size() - 1 && 
            abs(grid[i+1][j]) == currColor && abs(grid[i-1][j]) == currColor && 
            abs(grid[i][j+1]) == currColor && abs(grid[i][j-1]) == currColor){
                grid[i][j] = currColor;
            }


    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int hunt = grid[row][col];

        dfs(grid, row, col, hunt, vis);

        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(grid[i][j] < 0){
                    grid[i][j] = color;
                }
            }
        }
        return grid;
    }
};