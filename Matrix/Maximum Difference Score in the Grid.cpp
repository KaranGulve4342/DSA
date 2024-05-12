// LEETCODE 3148

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> temp(m, vector<int>(n, INT_MIN));
        temp[m-1][n-1] = grid[m-1][n-1];

        for(int i = m-1;i >= 0;i--){
            for(int j = n-1;j >= 0;j--){
                if(i < m-1){
                    temp[i][j] = max(temp[i][j], temp[i+1][j]);
                }
                if(j < n-1){
                    temp[i][j] = max(temp[i][j], temp[i][j+1]);
                }
                temp[i][j] = max(temp[i][j], grid[i][j]);
            }
        }
        int ans = INT_MIN;

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(i < m-1){
                    ans = max(ans, temp[i+1][j] - grid[i][j]);
                }
                if(j < n-1){
                    ans = max(ans, temp[i][j+1] - grid[i][j]);
                }
            }
        }
        return ans;
    }
};