#include<bits/stdc++.h>
using namespace std;

// using recursion
/*
int solve(int i, int j, vector<vector<int>>& grid){
    if(i == 0 && j == 0){
        return grid[i][j];
    }

    if(i < 0 || j < 0){
        return INT_MAX;
    }

    int up = grid[i][j] + solve(i-1, j, grid);
    int left = grid[i][j] + solve(i, j-1, grid);

    return min(left, up);
}
int minPathSum(vector<vector<int>> grid){
    int n = grid.size();
    int m = grid[0].size();

    return solve(n-1, m-1, grid);
}
*/

// using memoisation
/*
int solve(i, j, vector<vector<int>> grid, vector<vector<int>>& dp){
    if(i == 0 && j == 0){
        return grid[i][j];
    }

    if(i < 0 || j < 0){
        return INT_MAX;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int up = grid[i][j] + solve(i-1, j, grid, dp);
    int left = grid[i][j] + solve(i, j-1, grid, dp);

    return dp[i][j] = min(up, left);
}
int minPathSum(vector<vector<int>> grid){
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    return solve(n-1, m-1, grid, dp);
}
*/

// using tabulation

int minSumPath(vector<vector<int>> grid){
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(i == 0 && j == 0){
                dp[i][j] = grid[i][j];
            }
            else{
                int up = grid[i][j];
                if(i > 0){
                    up += dp[i-1][j];
                }
                else{
                    up += 1e9;
                }

                int left = grid[i][j];
                if(j > 0){
                    left += dp[i][j-1];
                }
                else{
                    left += 1e9;
                }

                dp[i][j] = min(left, up);
            }
        }
    }
    return dp[n-1][m-1];
}
