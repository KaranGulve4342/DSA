// GFG POTD

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long reversedBits(long long x) {
        // code here
        long long reversed = 0;
        
        // Iterate through each bit of the binary representation of x
        for (int i = 0; i < 32; ++i) {
            // Shift the reversed result to the left by one bit to make room for the next bit
            reversed <<= 1;
            
            // Check if the current bit of x is 1
            if (x & 1) {
                // If yes, set the least significant bit of the reversed result to 1
                reversed |= 1;
            }
            
            // Shift x to the right by one bit to process the next bit
            x >>= 1;
        }
        
        // Return the reversed binary form of x in decimal
        return reversed;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends