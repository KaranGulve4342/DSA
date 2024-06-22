// LEETCODE 542

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(mat[i][j] == 0){
                    distance[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while(!q.empty()){
            auto cell = q.front();
            auto x = cell.first;
            auto y = cell.second;
            q.pop();

            for(auto [dx, dy] : directions){
                int newX = x + dx;
                int newY = y + dy;

                if(newX >= 0 && newX < m && newY >= 0 && newY < n){
                    if(distance[newX][newY] > distance[x][y] + 1){
                        distance[newX][newY] = distance[x][y] + 1;
                        q.push({newX, newY});
                    }
                }
            }
        }

        return distance;
    }
};