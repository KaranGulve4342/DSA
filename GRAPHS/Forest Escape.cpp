// GFG CONTEST 14 JAN 2024

class Solution{
public:
    bool excapeForest(int n, int m, vector<vector<char> >&grid){
        bool ans = false;
        bool no_fire = true;

        queue<pair<int, int>> q;

        int i, j;
        int dis[n][m], dm[n][m];

        for(i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                dis[i][j] = -1;
                dm[i][j] = -1;
            }
        }

        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(grid[i][j] == 'X'){
                    no_fire = false;
                    dis[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        if(no_fire == true){
            return true;
        }

        while(q.empty()==false){
            i = q.front().first;
            j = q.front().second;
            q.pop();

            if(j - 1 >= 0 && dis[i][j-1] == -1){
                dis[i][j-1] = dis[i][j] + 1;
                q.push({i, j-1});
            }

            if(j+1 < m && dis[i][j+1] == -1){
                dis[i][j+1] = dis[i][j] + 1;
                q.push({i, j+1});
            }

            if(i-1 >= 0 && dis[i-1][j] == -1){
                dis[i-1][j] = dis[i][j] + 1;
                q.push({i-1, j});
            }

            if(i+1 < n && dis[i+1][j] == -1){
                dis[i+1][j] = dis[i][j] + 1;
                q.push({i+1, j});
            }
        }

        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(grid[i][j] == 'M'){
                    dm[i][j] = 0;
                    q.push({i, j});
                    break;
                }
            }
        }

        while(!q.empty()){
            i = q.front().first;
            j = q.front().second;
            q.pop();

            if(i == 0 || j == 0 || i == n-1 || j == m-1){
                ans = true;
                break;
            }

            if(dm[i-1][j] == -1 && dis[i-1][j] > dm[i][j]+1){
                dm[i-1][j] = dm[i][j] + 1;
                q.push({i-1, j});
            }
            if(dm[i+1][j] == -1 && dis[i+1][j] > dm[i][j]+1){
                dm[i+1][j] = dm[i][j] + 1;
                q.push({i+1, j});
            }
            if(dm[i][j-1] == -1 && dis[i][j-1] > dm[i][j]+1){
                dm[i][j-1] = dm[i][j]+1;
                q.push({i, j-1});
            }
            if(dm[i][j+1] == -1 && dis[i][j+1] > dm[i][j]+1){
                dm[i][j+1] = dm[i][j]+1;
                q.push({i, j+1});
            }
        }
        return ans;
    }
}