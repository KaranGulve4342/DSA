// gfg

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// #define ll long long
// class Solution{
// public:
//     vector<long long> nthRowOfPascalTriangle(int n) {
//         // code here
//         vector<vector<long long> > result;
        
//         for(int i = 0;i < n;i++){
//             vector<long long> ans(i+1, 1);
//             for(int j = 1;j < i;j++){
//                 ans[j] = result[i-1][j-1] + result[i-1][j];
//             }
//             result.push_back(ans);
//         }
//         return result[n-1];
//     }
// };

#define MOD 1000000007
class Solution{
public:
    vector<long long> nthRowOfPascalTriangle(int n) {
        vector<vector<long long>> result(n); // Initialize result with size n
        
        for(int i = 0; i < n; ++i){
            result[i].resize(i+1, 1); // Resize the current row to size i+1 and set all values to 1
            for(int j = 1; j < i; ++j){
                result[i][j] = ((result[i-1][j-1] % MOD) + (result[i-1][j]  % MOD))%MOD;
            }
        }
        return result[n-1];
    }
};

// #define MOD 1000000007

// class Solution{
// public:
//     vector<long long> nthRowOfPascalTriangle(int n) {
//         vector<long long> result;
//         result.push_back(1); // First element is always 1
        
//         for (int i = 1; i < n; ++i) {
//             vector<long long> temp(i + 1); // Initialize vector for the current row
            
//             temp[0] = 1; // First element of each row is always 1
//             temp[i] = 1; // Last element of each row is always 1
            
//             // Calculate values in between
//             for (int j = 1; j < i; ++j) {
//                 temp[j] = (result[j - 1] % MOD + result[j] % MOD) % MOD;
//             }
            
//             result = temp; // Update result with the current row
//         }
        
//         return result;
//     }
// };


//{ Driver Code Starts.


void printAns(vector<long long> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends