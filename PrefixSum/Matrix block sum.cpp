// LEETCODE 1314

class Solution {
public:
    int m, n;

    int solve(int i, int j, const vector<vector<int>>& sum){
        if(i < 0 || j < 0) return 0;
        if(i >= m) i = m-1;
        if(j >= n) j = n-1;
        return sum[i][j];
    }


    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        m = mat.size();
        n = mat[0].size();

        vector<vector<int>> sum(m, vector<int>(n, 0));

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                sum[i][j] = mat[i][j] + solve(i-1, j, sum) + solve(i, j-1, sum) - solve(i-1, j-1, sum);
            }
        }

        vector<vector<int>> ans(m, vector<int>(n, 0));

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                ans[i][j] = solve(i+k, j+k, sum) - solve(i+k, j-k-1, sum) - solve(i-k-1, j+k, sum) + solve(i-k-1, j-k-1, sum);
            }
        }

        return ans;
    }
};