// GFG

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
        vector<int> result;
        int N = matrix.size();
    
        for (int i = 0; i < 2 * N - 1; ++i) {
            int row = i < N ? 0 : i - N + 1;
            int col = i < N ? i : N - 1;
    
            while (row < N && col >= 0) {
                result.push_back(matrix[row][col]);
                ++row;
                --col;
            }
        }
    
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends