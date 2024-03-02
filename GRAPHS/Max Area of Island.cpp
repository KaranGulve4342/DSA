// LEETCODE 695

class Solution {
public:
    bool isValid(int i, int j, int m, int n, vector<vector<int>>&grid){
        if(i >= 0 && j >= 0 && i < m && j < n && grid[i][j]==1){
            return true;
        }
        return false;
    }
    void dfs(int i, int j, int m, int n, vector<vector<int>>& grid, int &area){
        area++;
        grid[i][j] = 0;

        if(isValid(i+1, j, m, n, grid)){
            dfs(i+1, j, m, n, grid, area);
        }
        if(isValid(i-1, j, m, n, grid)){
            dfs(i-1, j, m, n, grid, area);
        }
        if(isValid(i, j+1, m, n, grid)){
            dfs(i, j+1, m, n, grid, area);
        }
        if(isValid(i, j-1, m, n, grid)){
            dfs(i, j-1, m, n, grid, area);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid[0].size();
        int m = grid.size();

        int ans = 0;

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 1){
                    int area = 0;
                    dfs(i, j, m, n, grid, area);
                    ans = max(ans, area);
                }
            }
        }

        return ans;
    }
};