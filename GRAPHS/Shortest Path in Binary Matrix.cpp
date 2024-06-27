// LEETCODE 1091

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1){
            return -1;
        }

        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

        // Queue for BFS, storing (path length, row, column)
        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});

        grid[0][0] = 1; // marking the starting cell as visited

        while(!q.empty()){
            int pathLength = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;

            q.pop();

            if(row == n-1 && col == n-1){
                return pathLength;
            }

            for(auto dir : directions){
                int newRow = row + dir.first;
                int newCol = col + dir.second;

                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && grid[newRow][newCol] == 0){
                    q.push({pathLength + 1, {newRow, newCol}});
                    grid[newRow][newCol] = 1;
                }
            }
        }
        return -1;

    }
};