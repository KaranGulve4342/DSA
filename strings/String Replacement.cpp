// GFG CONTEST 2ND JUNE

//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    const int MOD = 1e9 + 7;
    int countOperations(string s) {
        // code herei
        int countB = 0;
        int ans = 0;
        
        for(int i = s.length() - 1;i >= 0;i--){
            if(s[i] == 'b'){
                countB++;
            }
            else{
                ans = (ans + countB)%MOD;
                
                countB = (countB + countB)%MOD;
            }
        }
        
        return ans % MOD;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        int res = obj.countOperations(s);

        cout << res << endl;
    }
}

// } Driver Code Ends