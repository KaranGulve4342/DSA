// GFG POTD 17 JAN 2024

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<vector<int>> uniquePerms(vector<int> &arr, int n) {
        vector<vector<int>> result;
        sort(arr.begin(), arr.end());  // Sort the array to handle duplicate elements
        vector<int> currentPermutation;
        vector<bool> used(n, false);

        backtrack(arr, result, currentPermutation, used, n);

        return result;
    }

private:
    void backtrack(const vector<int> &arr, vector<vector<int>> &result, vector<int> &currentPermutation, vector<bool> &used, int n) {
        if (currentPermutation.size() == n) {
            result.push_back(currentPermutation);
            return;
        }

        for (int i = 0; i < n; ++i) {
            // Skip duplicates to avoid duplicate permutations
            if (used[i] || (i > 0 && arr[i] == arr[i - 1] && !used[i - 1])) {
                continue;
            }

            currentPermutation.push_back(arr[i]);
            used[i] = true;

            // Recursively find permutations for the rest of the array
            backtrack(arr, result, currentPermutation, used, n);

            // Backtrack (undo the changes) for the next iteration
            currentPermutation.pop_back();
            used[i] = false;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends