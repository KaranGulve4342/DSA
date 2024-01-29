// GFG POTD 30 Jan 2024

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:

        int LCSof3Util(string A, string B, string C, int i, int j, int k, vector<vector<vector<int>>>& dp) {
            if (i == 0 || j == 0 || k == 0)
                return 0;

            if (dp[i][j][k] != -1)
                return dp[i][j][k];

            if (A[i-1] == B[j-1] && A[i-1] == C[k-1])
                return dp[i][j][k] = 1 + LCSof3Util(A, B, C, i-1, j-1, k-1, dp);
            else
                return dp[i][j][k] = max({LCSof3Util(A, B, C, i-1, j, k, dp),
                                            LCSof3Util(A, B, C, i, j-1, k, dp),
                                            LCSof3Util(A, B, C, i, j, k-1, dp)});
        }

        int LCSof3(string A, string B, string C, int n1, int n2, int n3) {
            vector<vector<vector<int>>> dp(n1+1, vector<vector<int>>(n2+1, vector<int>(n3+1, -1)));
            return LCSof3Util(A, B, C, n1, n2, n3, dp);
        }
};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        Solution obj;
        cout << obj.LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends