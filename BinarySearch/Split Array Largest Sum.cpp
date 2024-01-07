// GFG POTD 7 Jan 2023

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    bool solve(int arr[], int N, int K, int limit){
        int t = 1;
        int sum = limit;

        for(int i = 0; i < N; i++){
            if(sum >= arr[i]) sum -= arr[i];
            else{
                sum = limit;
                t++;
                if(sum < arr[i]) return false;
                sum -= arr[i];
            }
            if(t > K) return false;
        }
        return true;
    }

    int splitArray(int arr[], int N, int K) {
        int i = 0;
        int j = 0;
        int ans = INT_MAX;

        for(int it = 0; it < N; it++){
            i = max(i, arr[it]);
            j += arr[it];
        }

        while(i <= j){
            int mid = (i + j) / 2;
            if(solve(arr, N, K, mid)){
                ans = min(ans, mid);
                j = mid - 1;
            }
            else{
                i = mid + 1;
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
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends