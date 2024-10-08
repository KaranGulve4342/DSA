// GFG MULTISET

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestPerfectPiece(int arr[], int N) {
        // code here
        multiset<int> window;
        
        int i = 0;
        
        int ans = 0;
        
        for(int j = 0;j < N;j++){
            window.insert(arr[j]);
            
            while(((*window.rbegin() - *window.begin()) > 1) && i < N){
                window.erase(window.find(arr[i]));
                i++;
            }
            
            ans = max(ans, j-i+1);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.longestPerfectPiece(arr,N) << endl;
    }
    return 0;
}
// } Driver Code Ends