// GFG POTD 28TH JUNE 2024

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
string pattern(vector<vector<int>> &arr) {
        for (int i = 0; i < arr.size(); i++) {
            if (isRowPalindrome(arr[i])) {
                return to_string(i) + " R";
            }
        }

        for (int j = 0; j < arr[0].size(); j++) {
            if (isColPalindrome(arr, j)) {
                return to_string(j) + " C";
            }
        }

        return "-1";
    }

    bool isRowPalindrome(const vector<int>& row) {
        int lo = 0;
        int hi = row.size() - 1;

        while (lo <= hi) {
            if (row[lo] != row[hi]) {
                return false;
            }
            lo++;
            hi--;
        }
        return true;
    }

    bool isColPalindrome(const vector<vector<int>>& arr, int col) {
        int lo = 0;
        int hi = arr.size() - 1;

        while (lo <= hi) {
            if (arr[lo][col] != arr[hi][col]) {
                return false;
            }
            lo++;
            hi--;
        }
        return true;
    }
    
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends