// GFG POTD

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void matchPairs(int n, char nuts[], char bolts[]) {
        string s="!#$%&*?@^"; 
        int h=0;
        for(int i=0;i<=9;i++){
            for(int j=0;j<n;j++){ 
              
                if(s[i]==nuts[j]){                           //j=3 //j=2 //j=2 //j=3//j=4
                    swap(nuts[j],nuts[h]);             //#%$@^ //#$%@^ //#$%@^ //#$%@^ //#$%@^
                    bolts[h]=nuts[h]; 
                    h++;                  //h=1 //h=2 //h=3 //h=4 //h=5
                }
                if(h>n-1){
                    break;
                }
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(n, nuts, bolts);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends