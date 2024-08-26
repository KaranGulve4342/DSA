// GFG  => USING KADANE'S ALGORITHM

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int kadane(vector<int>& v){
        int maxi = v[0];
        int curr = v[0];
        
        for(int i = 1;i < v.size();i++){
            curr = max(v[i], v[i] + curr);
            maxi = max(maxi, curr);
        }
        
        return maxi;
    }
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        // code here
        int maxi = INT_MIN;
        
        for(int row = 0;row < R;row++){
            vector<int> v(C, 0);
            
            for(int i = row;i < R;i++){
                for(int j = 0;j < C;j++){
                    v[j] += M[i][j];
                }
                
                maxi = max(maxi, kadane(v));
            }
        }
        
        return maxi;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}
// } Driver Code Ends