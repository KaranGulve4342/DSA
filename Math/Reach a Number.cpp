// LEETCODE 754

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minSteps(int d) {
        int sum = 0;
        int i = 1;
        int moves = 0;
        
        while(true){
            sum += i;
            i++;
            moves++;
            
            if(sum == d) return moves;
            if(sum > d && ((sum - d)%2 == 0)){
                return moves;
            }
        }
        return moves;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int d;
        cin >> d;

        Solution ob;
        cout << ob.minSteps(d) << "\n";
    }
    return 0;
}
// } Driver Code Ends