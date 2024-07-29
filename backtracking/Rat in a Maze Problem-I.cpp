// GFG POTD

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool isSafe(int x, int y, int n, vector<vector<int>>& visited, vector<vector<int>>& mat){
        if(x >= 0 && x < n && y >= 0 && y < n && visited[x][y] == 0 && mat[x][y] == 1){
            return true;
        }
        return false;
    }
    void solve(vector<vector<int>>& mat, int n, vector<string>& ans, int x, int y, vector<vector<int>>& visited, string path){
        if(x == n-1 && y == n-1){
            ans.push_back(path);
            return;
        }
        
        visited[x][y] = 1;
        
        
        if(isSafe(x + 1, y, n, visited, mat)){
            path.push_back('D');
            solve(mat, n, ans, x + 1, y, visited, path);
            path.pop_back();
        }
        
        if(isSafe(x, y - 1, n, visited, mat)){
            path.push_back('L');
            solve(mat, n, ans, x, y-1, visited, path);
            path.pop_back();
        }
        
        if(isSafe(x, y+1, n, visited, mat)){
            path.push_back('R');
            solve(mat, n, ans, x, y+1, visited, path);
            path.pop_back();
        }
        
        if(isSafe(x-1, y, n, visited, mat)){
            path.push_back('U');
            solve(mat, n, ans, x-1, y, visited, path);
            path.pop_back();
        }
        
        visited[x][y] = 0;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        int n = mat.size();
        
        vector<string> ans;
        
        int srcX = 0;
        int srcY = 0;
        
        if(mat[0][0] == 0){
            return ans;
        }
        
        vector<vector<int>> visited(n, vector<int>(n, 0));
        
        string path = "";
        solve(mat, n, ans, srcX, srcY, visited, path);
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends