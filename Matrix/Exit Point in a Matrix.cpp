// GFG POTD 26TH APRIL 2024

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        // Code here
        vector<int> exitPoint = {0, 0}; // Initialize exit point

        // Directions: right, down, left, up (clockwise)
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dir = 0; // Start moving towards the right

        int row = 0, col = 0; // Initial position
        while (row >= 0 && row < n && col >= 0 && col < m) {
            // Check if current cell is 0 or 1
            if (matrix[row][col] == 0) {
                // Move in the current direction
                exitPoint = {row, col};
                row += directions[dir].first;
                col += directions[dir].second;
            } else {
                // Change direction to the right
                dir = (dir + 1) % 4;
                // Mark the encountered 1 as 0
                matrix[row][col] = 0;
            }
        }

        return exitPoint;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends