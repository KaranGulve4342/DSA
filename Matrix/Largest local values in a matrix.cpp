// LEETCODE 2373

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> ans(m-2, vector<int>(n-2, 0));

        for(int i = 1;i <= m-2;i++){
            for(int j = 1;j <= n-2;j++){
                int maxi = 0;

                maxi = max({maxi, grid[i-1][j-1], grid[i-1][j], grid[i-1][j+1]});
                maxi = max({maxi, grid[i][j-1], grid[i][j], grid[i][j+1]});
                maxi = max({maxi, grid[i+1][j-1], grid[i+1][j], grid[i+1][j+1]});

                ans[i-1][j-1] = maxi;
            }
        }

        return ans;
    }
};