// LEETCODE 329

class Solution {
public:
    int helper(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int dir[4][2] = {{0, 1}, {0,-1},{1, 0},{-1, 0}};

        int mx = 1;
        for(auto move : dir){
            int x = move[0] + i;
            int y = move[1] + j;

            if(x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size() && matrix[i][j] < matrix[x][y]){
                mx = max(mx, 1 + helper(x, y, matrix, dp));
            }
        }
        return dp[i][j] = mx;


    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        int result = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                result = max(result, helper(i, j, matrix, dp));
            }
        }
        return result;
    }
};