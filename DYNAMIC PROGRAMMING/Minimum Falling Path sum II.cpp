// LEETCODE 1289

class Solution {
public:
    int solve(int row, int col, vector<vector<int>>&grid, vector<vector<int>> &dp){
        if(row == grid.size() - 1){
            return grid[row][col];
        }

        if(dp[row][col] != -1){
            return dp[row][col];
        }

        int nextMin = INT_MAX;
        for(int nextRowCol = 0;nextRowCol < grid.size();nextRowCol++){
            if(nextRowCol != col){
                nextMin = min(nextMin, solve(row + 1, nextRowCol, grid, dp));
            }
        }

        return dp[row][col] = grid[row][col] + nextMin;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int answer = INT_MAX;

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m+1, vector<int>(n, -1));

        for(int col = 0;col < m;col++){
            answer = min(answer, solve(0, col, grid, dp));
        }

        return answer;
    }
};