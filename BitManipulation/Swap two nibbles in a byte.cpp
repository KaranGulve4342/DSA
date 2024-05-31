// GFG POTD 31ST MAY 2024

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int swapNibbles(int n) {
        int left_shifted = (n & 0x0F) << 4;  // Left shift lower nibble to higher nibble position
        int right_shifted = (n & 0xF0) >> 4; // Right shift higher nibble to lower nibble position
        return left_shifted | right_shifted; // Combine both nibbles
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.swapNibbles(n) << endl;
    }
    return 0;
}
// } Driver Code Ends