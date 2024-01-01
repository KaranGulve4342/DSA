// LEETCODE 62

/*
class Solution {
public:
    vector<vector<int>> dp;
    int f(int i, int j, int &m, int &n){
        if(i < 0 || j < 0 || i >= m || j >= n) return 0;
        if(i == m-1 && j == n-1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = f(i+1, j, m,n) + f(i, j+1,m,n);
    }
    int uniquePaths(int m, int n) {
        dp.clear();
        dp.resize(100, vector<int>(100, -1));
        if(dp[m-1][n-1] == 1) return 1;
        return f(0, 0,m,n);
    }
};
*/