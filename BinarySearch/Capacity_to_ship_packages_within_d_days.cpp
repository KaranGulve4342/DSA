// LEETCODE 1011

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findDays(int arr[], int capacity){
        int days = 1;
        int load = 0;
        
        for(int i = 0;i < sizeof(arr);i++){
            if(arr[i] + load > capacity){
                days++;
                load = arr[i];
            }
            else{
                load += arr[i];
            }
        }
        
        return days;
    }
    int leastWeightCapacity(int arr[], int n, int d) {
        // code here
        int lo = arr[0];
        int hi = arr[0];
        for(int i = 1;i < n;i++){
            lo = max(lo, arr[i]);
            hi += arr[i];
        }
        
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            
            int numberOfDays = findDays(arr, mid);
            
            if(numberOfDays <= d){
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        
        return lo;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, D;
        cin >> N;

        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        cin >> D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr, N, D) << endl;
    }
    return 0;
}
// } Driver Code Ends