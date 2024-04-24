// GFG POTD

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findMaxSum(int n, int m, vector<vector<int>> mat) {
        // code here
        int maxSum = INT_MIN;

        // Iterate through each cell of the matrix
        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < m - 2; j++) {
                // Calculate the sum of the hourglass centered at (i, j)
                int hourglassSum = mat[i][j] + mat[i][j + 1] + mat[i][j + 2] +
                                   mat[i + 1][j + 1] +
                                   mat[i + 2][j] + mat[i + 2][j + 1] +
                                   mat[i + 2][j + 2];

                // Update maxSum if necessary
                maxSum = max(maxSum, hourglassSum);
            }
        }

        // If maxSum is still INT_MIN, it means no hourglass was found
        // Return -1 in this case, otherwise return maxSum
        return (maxSum == INT_MIN) ? -1 : maxSum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, i, j;
        cin >> N >> M;
        vector<vector<int>> Mat(N, vector<int>(M));
        for (i = 0; i < N; i++)
            for (j = 0; j < M; j++) cin >> Mat[i][j];
        Solution ob;
        cout << ob.findMaxSum(N, M, Mat) << "\n";
    }
}
// } Driver Code Ends