// LEETCODE 3239

class Solution {
public:
    int m, n;
    vector<vector<int>> grid;
    int rowFlips(int r){
        int count = 0;
        for(int i = 0; i < n / 2; i++){
            if(grid[r][i] != grid[r][n - i - 1]){
                count++;
            }
        }
        return count;
    }
    int columnFlips(int c){
        int count = 0;
        for(int i = 0; i < m / 2; i++){
            if(grid[i][c] != grid[m - i - 1][c]){
                count++;
            }
        }
        return count;
    }

    int minFlips(vector<vector<int>>& grid) {
        this->grid = grid;
        m = grid.size();
        n = grid[0].size();

        int rowFlipsTotal = 0;
        int columnFlipsTotal = 0;

        for(int i = 0; i < m; i++){
            rowFlipsTotal += rowFlips(i);
        }

        for(int i = 0; i < n; i++){
            columnFlipsTotal += columnFlips(i);
        }
        return min(rowFlipsTotal, columnFlipsTotal);
    }
};