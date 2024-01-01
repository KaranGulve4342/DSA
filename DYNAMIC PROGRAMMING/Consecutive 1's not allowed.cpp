// GFG

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	
    ll countStrings(int n) {
        ll a[n], b[n];
        const int MOD = 1e9 + 7;
        a[0] = b[0] = 1;
        for (int i = 1; i < n; i++) {
            a[i] = (a[i-1] + b[i-1]) % MOD;
            b[i] = a[i-1] % MOD;
        }
        return (a[n-1] + b[n-1]) % MOD;
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
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends