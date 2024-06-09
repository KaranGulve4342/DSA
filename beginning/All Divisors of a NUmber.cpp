// GFG

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void print_divisors(int n) {
        set<int> uset;
        for(int i = 1; i * i <= n; i++){
            if(n % i == 0){
                uset.insert(i);
                uset.insert(n / i);
            }
        }
        
        for(auto divisor : uset){
            cout << divisor << " ";
        }
        // cout << endl; // Add a newline after printing the divisors
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Solution ob;
        ob.print_divisors(n);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends