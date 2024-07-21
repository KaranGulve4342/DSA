// GFG POTD 21ST JULY 2024

//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
        const int MOD = 1e9 + 7;
        
        int n = arr.size();
        
        long long int pos = 1;
        long long int prev = INT_MIN;
        
        long long int zero = 0;
        
        for(int i = 0;i < n;i++){
            if(arr[i] != 0){
                pos = (1LL * pos * arr[i]) % MOD;
                if(arr[i] < 0){
                    prev = max(prev, 1LL * arr[i]);
                }
            }
            else{
                zero++;
            }
        }
        
        if(zero == arr.size()){
            return 0;
        }
        
        if(pos < 0){
            pos /= prev;
        }
        
        return (1LL * pos) % MOD;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends