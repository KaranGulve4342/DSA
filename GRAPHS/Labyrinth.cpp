#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));

    pair<int, int> start, end;

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> grid[i][j];

            if(grid[i][j] == 'A'){
                start = {i, j};
            }
            else if(grid[i][j] == 'B'){
                end = {i, j};
            }
        }
    }

    queue<pair<int, int>> q;

    q.push(start);

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    vector<char> dirChar = {'R', 'D', 'L', 'U'};

    visited[start.first][start.second] = true;

    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));

    vector<vector<char>> path(n, vector<char>(m));

    bool found = false;

    while(!q.empty()){
        auto x = q.front().first;
        auto y = q.front().second;

        q.pop();

        if(x == end.first && y == end.second){
            found = true;
            break;
        }

        for(int i = 0;i < 4;i++){
            int newx = x + directions[i].first;
            int newy = y + directions[i].second;

            if(newx >= 0 && newx < n && newy >= 0 && newy < m && grid[newx][newy] != '#' && !visited[newx][newy]){
                visited[newx][newy] = true;

                q.push({newx, newy});

                parent[newx][newy] = {x, y};

                path[newx][newy] = dirChar[i];
            }
        }
    }

    if(!found){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;

        string ans = "";

        pair<int, int> curr = end;

        while(curr != start){
            ans += path[curr.first][curr.second];

            curr = parent[curr.first][curr.second];
        }

        reverse(ans.begin(), ans.end());

        cout<<ans.size()<<endl;
        cout<<ans<<endl;
    }

    return 0;
}