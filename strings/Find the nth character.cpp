// GFG POTD 9TH MARCH 2024

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        int len = s.length();
        for (int i = 0; i < r; ++i) {
            string temp = "";
            for (int j = 0; j < len; ++j) {
                if (s[j] == '0') {
                    temp += "01";
                } else {
                    temp += "10";
                }
            }
            s = temp;
        }
        return s[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends