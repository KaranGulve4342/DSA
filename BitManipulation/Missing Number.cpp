//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int missingNumber(vector<int>& array, int n) {
        int ans = 0;
        
        // XOR all numbers from 1 to N
        for (int i = 1; i <= n; i++) {
            ans ^= i;
        }
        
        // XOR all elements in the array
        for (int num : array) {
            ans ^= num;
        }
        
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

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];
        Solution obj;
        cout << obj.missingNumber(array, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends