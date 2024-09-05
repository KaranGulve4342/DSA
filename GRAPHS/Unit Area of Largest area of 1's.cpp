// GFG PRACTICE

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    bool isValid(int i, int j, int n, int m, vector<vector<int>>& grid){
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != 1){
            return false;
        }
        return true;
    }
    int dfs(int x, int y, int n, int m, vector<vector<int>>& grid){
        int count = 0;
        
        count++;
        
        grid[x][y] = 0;
        
        vector<pair<int, int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}, {1,1}, {-1,-1},{1,-1}, {-1,1}}; 
        
        for(int i = 0;i < 8;i++){
            int dx = x + dirs[i].first;
            int dy = y + dirs[i].second;
            
            if(isValid(dx, dy, n, m, grid)){
                count += dfs(dx, dy, n, m, grid);
            }
        }
        
        return count;
        
        
    }
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here\

        int n = grid.size();
        int m = grid[0].size();
        
        int maxi = 0;
        
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                
                if(grid[i][j] == 1){
                    int count = dfs(i, j, n, m, grid);
                
                    maxi = max(maxi, count);   
                }
            }
        }
        
        return maxi;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends