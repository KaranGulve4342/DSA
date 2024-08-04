// LEETCODE 3242

class neighborSum {
public:
    vector<vector<int>> grid;
    unordered_map<int, pair<int, int>> umap;
    int n;
    neighborSum(vector<vector<int>>& grid) {
        this->grid = grid;
        n = grid.size();

        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                umap[grid[i][j]] = {i,j};
            }
        }
    }
    
    int adjacentSum(int value) {
        int sum = 0;

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        auto start = umap[value];

        auto x = start.first;
        auto y = start.second;

        for(auto dir : directions){
            int X = x + dir.first;
            int Y = y + dir.second;

            if(X >= 0 && X < n && Y >= 0 && Y < n){
                sum += grid[X][Y];
            }
        }

        return sum;
    }
    
    int diagonalSum(int value) {
        int sum = 0;

        vector<pair<int, int>> directions = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

        auto start = umap[value];

        auto x = start.first;
        auto y = start.second;

        for(auto dir : directions){
            int X = x + dir.first;
            int Y = y + dir.second;

            if(X >= 0 && X < n && Y >= 0 && Y < n){
                sum += grid[X][Y];
            }
        }

        return sum;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */