// GFG POTD 3 Jan'24

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        int n = S.length();
        if (n < 3) return -1; // Early exit if length is less than 3
        
        int count[3] = {0}; // Array to count occurrences of '0', '1', '2'
        int left = 0, right = 0;
        int minLength = INT_MAX;
        int found = 0;

        while (right < n) {
            count[S[right] - '0']++;

            if (count[S[right] - '0'] == 1) {
                found++;
            }

            if (found == 3) {
                while (count[S[left] - '0'] > 1) {
                    count[S[left] - '0']--;
                    left++;
                }

                minLength = min(minLength, right - left + 1);

                // Move left pointer to find other substrings
                count[S[left] - '0']--;
                left++;
                found--;
            }

            right++;
        }

        return (minLength == INT_MAX) ? -1 : minLength;
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
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends