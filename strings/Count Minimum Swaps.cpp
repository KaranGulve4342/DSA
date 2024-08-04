// GFG CONTEST 

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minSwaps(string S) {
        // code here
        int oddSum = 0;
        int evenSum = 0;
        int N = S.length();
        
        for(int i = 0;i < N;i++){
            if(i&1){
                oddSum += (S[i] == '1');
            }   
            else{
                evenSum += (S[i] == '1');
            }
        }
        
        int diff = abs(oddSum - evenSum);
        
        if(diff&1) return -1;
        
        return diff/2;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        cout << obj.minSwaps(a) << endl;
    }
}

// } Driver Code Ends