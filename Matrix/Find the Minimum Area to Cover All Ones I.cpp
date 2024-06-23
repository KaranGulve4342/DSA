// LEETCODE 3195

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int r1 = INT_MAX;
        int c1 = INT_MAX;
        int r2 = INT_MIN;
        int c2 = INT_MIN;

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 1){
                    r1 = min(r1, i);
                    r2 = max(r2, i);
                    c1 = min(c1, j);
                    c2 = max(c2, j);
                }
            }
        }

        return (r2-r1+1)*(c2-c1+1);
    }
};