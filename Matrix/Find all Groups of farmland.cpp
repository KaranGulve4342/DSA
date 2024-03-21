// LEETCODE 1992

class Solution {
public:
    void fill(vector<vector<int>>& land, int i, int j, int r1, int c1){
        for(int x = i;x < r1;x++){
            for(int y = j;y < c1;y++){
                land[x][y] = 0;
            }
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();

        vector<vector<int>> ans;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(land[i][j] == 0){
                    continue;
                }
                if(land[i][j] == 1){
                    int r1 = i;
                    int c1 = j;

                    while(r1 < m && land[r1][j] == 1){
                        r1++;
                    }
                    while(c1 < n && land[i][c1] == 1){
                        c1++;
                    }

                    fill(land, i, j, r1, c1);
                    ans.push_back({i, j, r1-1, c1-1});
                }
            }
        }
        return ans;
    }
};