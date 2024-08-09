// LEETCODE 840

class Solution {
public:
    vector<bool> visited;
    bool check(vector<vector<int>>& grid, int r, int c){
        visited.clear();
        visited.resize(10, false);

        for(int i = 0;i < 3;i++){
            for(int j = 0;j < 3;j++){
                int num = grid[r + i][c + j];

                if(visited[num] == true){
                    return false;
                }

                if(num < 1 || num > 9){
                    return false;
                }

                visited[num] = true;
            }
        }

        int d1 = grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2];
        int d2 = grid[r+2][c] + grid[r+1][c+1] + grid[r][c+2];

        if(d1 != d2){
            return false;
        }

        int row1 = grid[r][c] + grid[r][c+1] + grid[r][c+2];
        int row2 = grid[r+1][c] + grid[r+1][c+1] + grid[r+1][c+2];
        int row3 = grid[r+2][c] + grid[r+2][c+1] + grid[r+2][c+2];

        if(row1 != d1 || row2 != d1 || row3 != d1){
            return false;
        }

        int col1 = grid[r][c] + grid[r][c+1] + grid[r][c+2];
        int col2 = grid[r][c + 1] + grid[r+1][c+1] + grid[r+2][c+1];
        int col3 = grid[r][c+2] + grid[r+1][c+2] + grid[r+2][c+2];

        if(col1 != d1 || col2 != d1 || col3 != d1){
            return false;
        }

        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;

        for(int i = 0;i < m-2;i++){
            for(int j = 0;j < n-2;j++){
                if(check(grid, i, j)){
                    ans++;
                }
            }
        }

        return ans;
    }
};