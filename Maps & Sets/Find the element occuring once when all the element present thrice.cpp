// GFG POTD 4th Jan'24

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int singleElement(int arr[] ,int N) {
        unordered_map<int, int> freqMap;
    
        // Store the frequency of each element in the array
        for (int i = 0; i < N; i++) {
            freqMap[arr[i]]++;
        }
    
        // Iterate through the map to find the element with frequency 1
        for (auto it = freqMap.begin(); it != freqMap.end(); it++) {
            if (it->second == 1) {
                return it->first;
            }
        }
    
        return -1; // Element not found
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
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.singleElement(arr,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Endsw