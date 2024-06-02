// GFG CONTEST 2ND JUNE 2024

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string isPossible(int a, int b, int c) {
        // code here    
        vector<int> temp = {a, b, c};
        sort(temp.begin(), temp.end());
        
        if(temp[2] < temp[0] + temp[1]){
            return "YES";
        }
        return "NO";
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int a;
        scanf("%d", &a);

        int b;
        scanf("%d", &b);

        int c;
        scanf("%d", &c);

        Solution obj;
        string res = obj.isPossible(a, b, c);

        cout << res << "\n";
    }
}

// } Driver Code Ends