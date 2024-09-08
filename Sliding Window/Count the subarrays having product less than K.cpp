// GFG PRACTICE

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
  public:
    long long countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        // long long i = 0;
        // long long j = 0;
        
        // long long count = 0;
        
        // long long product = 1;
        // long long ans = 0;
        
        // for(int i = 0;i < n;i++){
        //     product = 1;
        //     count = 0;
        //     j = i;
            
        //     while(j < n && product*a[j] < k){
        //         count++;
        //         product *= a[j];
        //         j++;
        //     }
            
        //     ans += count;
        // }
        
        // return ans;
        
        long long left = 0;
        long long right = 0;
        
        long long ans = 0;
        
        long long product = 1;
        
        while(right < n){
            product *= a[right];
            
            while(left <= right && product >= k){
                product /= a[left];
                left++;
            }
            
            ans += (right - left + 1);
            
            right++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends