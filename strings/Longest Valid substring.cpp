// GFG PRACTICE

// EVERY PROBELM IS SOLVABLE

//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        int n = s.length();
        int openCount = 0, closeCount = 0, maxi = 0;
        
        // Left to Right pass
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                openCount++;
            } 
            else if (s[i] == ')') {
                closeCount++;
            }
            
            if (openCount == closeCount) {
                maxi = max(maxi, 2 * closeCount);
            } 
            else if (closeCount > openCount) {
                openCount = closeCount = 0;
            }
        }
        
        openCount = closeCount = 0;
        
        for(int i = n-1;i >= 0;i--){
            if (s[i] == '(') {
                openCount++;
            } 
            else if (s[i] == ')') {
                closeCount++;
            }
            
            if (openCount == closeCount) {
                maxi = max(maxi, 2 * closeCount);
            } 
            else if (openCount > closeCount) {
                openCount = closeCount = 0;
            }
        }
        
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends