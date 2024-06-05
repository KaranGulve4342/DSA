// GFG

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        int sum_a = accumulate(a, a + n, 0);
        int sum_b = accumulate(b, b + m, 0);
        
        // If the difference between sums is odd, no such pair exists
        int diff = sum_a - sum_b;
        if (diff % 2 != 0) {
            return -1;
        }
        
        // Calculate the target value that should be equal to a[i] - b[j]
        int target = diff / 2;
        
        // Create a set of elements from array b for quick lookup
        unordered_set<int> b_set(b, b + m);
        
        // Iterate over each element in array a
        for (int i = 0; i < n; i++) {
            // Check if there exists an element in b that satisfies the condition
            if (b_set.find(a[i] - target) != b_set.end()) {
                return 1;
            }
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends