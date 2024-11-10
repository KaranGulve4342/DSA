// GFG POTD

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minIncrements(vector<int> arr) {
        int N = arr.size();
         sort(arr.begin(),arr.end());
        
        int prev = arr[0];
        int ans = 0;
        for(int i=1; i<N; i++)
        {
            if(arr[i]>prev) prev = arr[i];
            else
            {
                ans+= (prev + 1 - arr[i]);
                prev++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int ans = ob.minIncrements(a);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends