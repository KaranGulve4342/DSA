// GFG PRACTICE

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        if(X == 0 && Y == 0){
            return 0;
        }
        
        // If the start position is blocked
        if(A[0][0] != 1){
            return -1;
        }
        
        // Queue for BFS: stores {steps, {row, col}}
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, 0}});
        
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        visited[0][0] = true;
        
        // Directions for moving up, down, left, right
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while(!q.empty()){
            int row = q.front().second.first;
            int col = q.front().second.second;
            int step = q.front().first;
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int newRow = row + dirs[i].first;
                int newCol = col + dirs[i].second;
                
                if(newRow >= 0 && newRow < N && newCol >= 0 && newCol < M){
                    if(A[newRow][newCol] == 1 && !visited[newRow][newCol]){
                        
                        if(newRow == X && newCol == Y){
                            return step + 1;
                        }
                        
                        visited[newRow][newCol] = true;
                        q.push({step + 1, {newRow, newCol}});
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
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends