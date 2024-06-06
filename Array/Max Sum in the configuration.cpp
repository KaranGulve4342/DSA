// GFG POTD 6TH JUNE 2024

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/
class Solution {
  public:
    long long max_sum(int a[], int n) {
        // Your code here
        long sum = 0, cur = 0, ans = 0;
        for (int i = 0; i < n; i++)     sum += a[i];
        for (int i = 0; i < n; i++)     cur += (long)i * a[i];
        
        ans = cur;

        for (int i = 1; i < n; i++) {
            long temp = cur - (sum - a[i - 1]) + (long)a[i - 1] * (n - 1);

            ans = max(ans,temp);
            cur = temp;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends