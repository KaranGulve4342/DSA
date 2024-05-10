// GFG POTD : Juggler Sequence 11TH MAY 2024

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> jugglerSequence(int n) {
        // code here
        vector<int> ans;
        ans.push_back(n);
        int prev = n;
        while(prev != 1){
            if(prev&1){
                int temp = pow(prev, 1.5);
                ans.push_back(temp);
                prev = temp;
            }
            else{
                int temp = pow(prev, 0.5);
                ans.push_back(temp);
                prev = temp;
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
        cin >> n;

        Solution ob;
        vector<int> ans = ob.jugglerSequence(n);
        for (int u : ans)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends