// GFG PRACTICE

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // Code here
        int M = grid.size();
        int N = grid[0].size();
        
        vector<vector<int>> ans(M, vector<int>(N, -1));
        
        queue<pair<int, int>> q;
        
        for(int i = 0;i < M;i++){
            for(int j = 0;j < N;j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }
        
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while(!q.empty()){
            int sz = q.size();
            
            while(sz--){
                int r = q.front().first;
                int c = q.front().second;
                
                q.pop();
                
                for(int i = 0;i < 4;i++){
                    int newRow = r + dirs[i].first;
                    int newCol = c + dirs[i].second;
                    
                    if(newRow < 0 || newCol < 0 || newRow >= M || newCol >= N || ans[newRow][newCol] != -1){
                        continue;
                    }
                    q.push({newRow, newCol});
                    
                    ans[newRow][newCol] = ans[r][c] + 1;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        vector<vector<int>> ans = obj.nearest(grid);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends