// LEETCODE 1765

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int row = isWater.size();
        int col = isWater[0].size();

        vector<vector<int>> ans(row, vector<int>(col, INT_MAX));

        queue<pair<int, int>> q;

        for(int i = 0;i < row;i++){
            for(int j = 0;j < col;j++){
                if(isWater[i][j] == 1){
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            int dx[4] = {0, 0, -1, 1};
            int dy[4] = {-1, 1, 0, 0};

            for(int i = 0;i < 4;i++){
                int newx = x + dx[i];
                int newy = y + dy[i];

                if(newx >= 0 && newx < row && newy >= 0 && newy < col && ans[newx][newy] > 1 + ans[x][y]){
                    ans[newx][newy] = 1 + ans[x][y];
                    q.push({newx, newy});
                }
            }
        }
        return ans;
    }
};