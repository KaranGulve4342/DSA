// GFG POTD

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
        // Array to store frequency of each character
        int freq[26] = {0};
        
        // Calculate frequency of each character
        for(char ch : s) {
            freq[ch - 'a']++;
        }
        
        int x = 0, y = 0;
        
        // Check each character from 'a' to 'z'
        for(int i = 0; i < 26; i++) {
            if(freq[i] > 0) { // Only consider characters with positive frequency
                if ((i + 1) % 2 == 0 && freq[i] % 2 == 0) {
                    // Even position (i+1) and even frequency
                    x++;
                } else if ((i + 1) % 2 == 1 && freq[i] % 2 == 1) {
                    // Odd position (i+1) and odd frequency
                    y++;
                }
            }
        }
        
        // Determine if (x + y) is even or odd
        if ((x + y) % 2 == 0) {
            return "EVEN";
        } else {
            return "ODD";
        }
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends