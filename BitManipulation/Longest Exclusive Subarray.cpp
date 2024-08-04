// GFG CONTEST 4TH AUGUST

//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int maxLength(vector<int> a) {
        // code here
        int n = a.size();
        
        int ans = 0;
        
        for(int i = 1;i <= 30;i++){
            int mask = (1 << i) - 1;
            int curr = 0;
            int len = 0;
            
            for(int j = 0;j < n;j++){
                if((a[j]&mask) != a[j]){
                    curr = 0;
                    len = 0;
                    continue;
                }
                
                curr |= a[j];
                len++;
                
                if(curr == mask){
                    ans = max(ans, len);
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
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        Solution ob;
        cout << ob.maxLength(a) << endl;
    }
    return 0;
}
// } Driver Code Ends