// GFG PRACTICE

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    long long countTriplets(int n, long long sum, long long arr[]) {
        // Your code goes here
        long long ans = 0;
        
        sort(arr, arr + n);
        
        for(int i = 0;i < n-2;i++){
            long long left = i+1;
            long long right = n-1;
            
            while(left < right){
                long long currSum = arr[i] + arr[left] + arr[right];
                
                if(currSum < sum){
                    ans += (right - left);
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        long long sum;
        cin >> n >> sum;
        long long arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countTriplets(n, sum, arr);

        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends