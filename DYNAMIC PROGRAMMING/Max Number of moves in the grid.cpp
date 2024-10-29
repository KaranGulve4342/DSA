// LEETCODE 2684

class Solution {
public:
    vector<pair<int, int>> dirs = {{0, 1}, {1, 1}, {-1, 1}};
    vector<vector<int>> dp;
    int n, m;

    int solve(int i, int j, vector<vector<int>>& grid) {
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = 0;

        for (auto dir : dirs) {
            int newx = i + dir.first;
            int newy = j + dir.second;

            if (newx >= 0 && newx < n && newy >= 0 && newy < m && grid[i][j] < grid[newx][newy]) {
                ans = max(ans, 1 + solve(newx, newy, grid));
            }
        }

        return dp[i][j] = ans;
    }

    int maxMoves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        dp.assign(n, vector<int>(m, -1));  // Correct size for dp

        int maxMoves = 0;

        // Try to start from each cell in the first column
        for (int i = 0; i < n; i++) {
            maxMoves = max(maxMoves, solve(i, 0, grid));
        }

        return maxMoves;
    }
};
