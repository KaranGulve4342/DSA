// LEETCODE 3341

class Solution {
public:
    vector<pair<int, int>> moves = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        set<tuple<int, int, int>> q;

        q.insert({0, 0, 0});

        dist[0][0] = 0;

        while(!q.empty()){
            auto [distance, x, y] = *q.begin();

            q.erase(*q.begin());

            for(auto move : moves){
                int newX = move.first + x;
                int newY = move.second + y;

                if(newX >= 0 && newX < n && newY >= 0 && newY < m && dist[newX][newY] > max(dist[x][y] + 1, moveTime[newX][newY] + 1)){
                    q.erase({dist[newX][newY], newX, newY});

                    dist[newX][newY] = max(dist[x][y] + 1, moveTime[newX][newY] + 1);

                    q.insert({dist[newX][newY], newX, newY});
                }
            }
        };

        return dist[n-1][m-1];
    }
};