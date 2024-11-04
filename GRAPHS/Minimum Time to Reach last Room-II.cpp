// LEETCODE 3342

class Solution {
public:
    vector<pair<int, int>> moves = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(2, INT_MAX)));

        set<tuple<int, int, int, int>> q;

        q.insert({0, 0, 0, 0});

        dist[0][0][0] = 0;

        while(!q.empty()){
            auto [distance, x, y, moveState] = *q.begin();

            q.erase(q.begin());

            int cost = (moveState ^ 1) ? 1 : 2;

            for(auto direction : moves){
                int newX = x + direction.first;
                int newY = y + direction.second;

                if(newX >= 0 && newX < n && newY >= 0 && newY < m &&
                    dist[newX][newY][moveState ^ 1] > max(dist[x][y][moveState] + cost, moveTime[newX][newY] + cost)){
                        
                        q.erase({dist[newX][newY][moveState ^ 1], newX, newY, moveState ^ 1});

                        dist[newX][newY][moveState ^ 1] = max(dist[x][y][moveState] + cost, moveTime[newX][newY] + cost);

                        q.insert({dist[newX][newY][moveState ^ 1], newX, newY, moveState ^ 1});
                    }
                }
            }
        
        return min(dist[n-1][m-1][0], dist[n-1][m-1][1]);
    }
};
