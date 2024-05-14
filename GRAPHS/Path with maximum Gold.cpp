// LEETCODE 1219

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j, int m, int n){
        if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j] == 1 || grid[i][j] == 0) return 0;

        int move[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        visited[i][j] = 1;

        int ans = grid[i][j];
        for(int k = 0; k < 4; k++){
            int newr = i + move[k][0];
            int newc = j + move[k][1];

            if(newr >= 0 && newr < m && newc >= 0 && newc < n && !visited[newr][newc]){
                ans = max(ans, grid[i][j] + solve(grid, visited, newr, newc, m, n));
            }
        }

        // Marking the cell as unvisited after exploring its adjacent cells
        visited[i][j] = 0;
        return ans;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;
        vector<vector<int>>visited(m, vector<int>(n, 0));

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] != 0){
                    ans = max(ans, solve(grid, visited, i, j, m, n));
                }
            }
        }

        return ans;
    }
};