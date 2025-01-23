// LEETCODE 1267

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> rowCounts(n, 0);
        vector<int> colCounts(m, 0);

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 1){
                    rowCounts[j]++;
                    colCounts[i]++;
                }
            }
        }

        int ans = 0;

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 1){
                    ans += (rowCounts[j] > 1 || colCounts[i] > 1);
                }
            }
        }

        return ans;
    }
};