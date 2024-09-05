// GFG PRACTICE

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int m = grid.size();
        int n = grid[0].size();
        
        if(source.first == destination.first && source.second == destination.second){
            return 0;
        }
        
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        
        dist[source.first][source.second] = 0;
        
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {source.first, source.second}});
        
        while(!q.empty()){
            int dis = q.front().first;
            
            int row = q.front().second.first;
            int col = q.front().second.second;
            
            q.pop();
            
            for(int i = 0;i < 4;i++){
                int newRow = row + dirs[i].first;
                int newCol = col + dirs[i].second;
                
                if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && grid[newRow][newCol] == 1){
                    if(dis + 1 < dist[newRow][newCol]){
                        dist[newRow][newCol] = dis + 1;
                        
                        if(newRow == destination.first && newCol == destination.second){
                            return dis + 1;
                        }
                        q.push({dis + 1, {newRow, newCol}});
                    }
                }
            }
        }
        
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends