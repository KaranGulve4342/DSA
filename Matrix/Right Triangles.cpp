// LEETCODE 3128

class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        long long m = grid.size();
        long long n = grid[0].size();
        long long count = 0;
        
        vector<int> rows(m, 0);
        vector<int> cols(n, 0);
        
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                rows[i]+=grid[i][j];
                cols[j]+=grid[i][j];
            }
        }
        
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 1){
                    count += ((rows[i] - 1) * (cols[j] - 1));
                }
            }
        }
        
        return count;
    }
};