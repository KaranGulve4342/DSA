// GFG CONTEST 04 FEB 2024

#include<bits/stdc++.h>
using namespace std;

vector<int> dx = {0, 0, 1, -1};
vector<int> dp = {1, -1, 0, 0}; // movement arrays

int solve(int i, int j, vector<vector<int> >&grid){
    int answer = grid[i][j];
    int store = grid[i][j];

    grid[i][j] = 0; // this is done so as to not revist the previously visited cell in the grid

    int mx = 0;

    for(int idx = 0;idx < 4;idx++){
        int x = i + dx[idx];
        int y = i + dy[idx];

        if(x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] != 0){
            mx = max(mx, solve(i, j, grid));
        }
    }

    grid[i][j] = store; // back to the previous value
    // as we need original values for the next recursion
    answer += mx;
    return answer;
}

int maximum(int N, vector<vector<int> >&grid){
    int answer = 0;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            if(grid[i][j] != 0 && (i + j)%2 != 0){
                answer = max(answer, solve(i, j, grid));
            }
        }
    }
    return ans;
}