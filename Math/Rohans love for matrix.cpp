// GFG POTD 23TH APRIL 2024

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int firstElement(int n) {
        // code here
        // code here
        int mod= 1000000007;
        // base case likho
        if(n<=2) return 1;
        //fibo wal CODE LIKHO
        int one=1;
        int two=1;
        int sum=0;
        for(int i=3 ; i<=n; i++){
            sum=(one+two)%mod;
            one = two;
            two=sum;
        }
        return sum;
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
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends