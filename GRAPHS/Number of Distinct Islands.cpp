// GFG PRACTICE

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int i, int j, vector<vector<int>>& grid, string&s, string direction){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()){
            return;
        }
        
        if(grid[i][j] == 0 || grid[i][j] == 2){
            return;
        }
        
        grid[i][j] = 2;
        
        s += direction;
        
        dfs(i+1, j, grid,s, "r");
        dfs(i, j+1, grid,s, "d");
        dfs(i-1, j, grid,s, "u");
        dfs(i, j-1, grid,s, "l");
        
        s += "b";
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        
        unordered_set<string> ans;
        for(int i = 0;i < grid.size();i++){
            for(int j = 0;j < grid[0].size();j++){
                if(grid[i][j] == 1){
                    string t = "";
                    dfs(i, j, grid, t, "o");
                    ans.insert(t);
                }
            }
        }
        
        return ans.size();
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
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends