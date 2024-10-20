// GFG POTD

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int countgroup(vector<int>& arr) {
        // Complete the function
        
        int n = arr.size();
        
        const int MOD = 1e9 + 7;
        int xorr = 0;
        
        for(int i = 0;i < n;i++){
            xorr ^= arr[i];
        }
        
        if(xorr > 0){
            return 0;
        }
        
        int ans = 1;
        for(int i = 0;i < n-1;i++){
            ans = (ans*2)%MOD;
        }
        
        return ans-1;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int ans = obj.countgroup(arr);
        cout << ans << endl;
    }
}

// } Driver Code Ends