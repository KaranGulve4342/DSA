#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &visited){
    visited[i][j] = true;

    for(auto dir : directions){
        auto x = i + dir.first;
        auto y = j + dir.second;

        if(x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == '.' && !visited[x][y]){
            dfs(x, y, grid, visited);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    int ans = 0;

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(!visited[i][j] && grid[i][j] == '.'){
                dfs(i, j, grid, visited);
                ans++;
            }
        }
    }

    cout<<ans<<endl;

    return 0;

}