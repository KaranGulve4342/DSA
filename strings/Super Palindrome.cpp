// GFG CONTEST 2ND JUNE 2024

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isPalindrome(long long n) {
        string s = to_string(n);
        string rev = s;
        reverse(rev.begin(), rev.end());
        return s == rev;
    }
    
    int countSuperPalindrome(long long l, long long r) {
        int count = 0;
        
        // start from the smallest possible integer whose square is >= l
        long long start = sqrt(l);
        if (start * start < l) {
            start++;
        }
        
        // go up to the largest possible integer whose square is <= r
        long long end = sqrt(r);
        
        for (long long i = start; i <= end; i++) {
            if (isPalindrome(i * i)) {
                count++;
            }
        }
        
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int l;
        scanf("%d", &l);

        int r;
        scanf("%d", &r);

        Solution obj;
        int res = obj.countSuperPalindrome(l, r);

        cout << res << endl;
    }
}

// } Driver Code Ends