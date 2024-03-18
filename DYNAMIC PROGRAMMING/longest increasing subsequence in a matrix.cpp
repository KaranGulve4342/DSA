// LEETCODE 329

class Solution {
public:
    int helper(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if (dp[i][j] != -1){
            return dp[i][j];
        }

        int mx = 1;
        int dirs[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        for (auto& dir : dirs) {
            int x = i + dir[0], y = j + dir[1];
            if (x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size() && matrix[x][y] > matrix[i][j]) {
                mx = max(mx, 1 + helper(x, y, matrix, dp));
            }
        }
        
        return dp[i][j] = mx;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        int result = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                result = max(result, helper(i, j, matrix, dp));
            }
        }
        
        return result;
    }
};
