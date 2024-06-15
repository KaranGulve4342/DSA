// GFG POTD 15TH JUNE 2024

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<vector<vector<long long>>> dp;
    
    long long solve(int count, int i, int j, int n){
        if(count == n) return 1;
        
        if(dp[count][i][j] != -1){
            return dp[count][i][j];
        }
        
        int dr[] = {0, 0, -1, 1};
        int dc[] = {1, -1, 0, 0};
        
        long long ans = 0;
        ans += solve(count + 1, i, j, n);
        
        for(int idx = 0;idx < 4;idx++){
            int newi = i + dr[idx];
            int newj = j + dc[idx];
            
            if(newi <= 4 && newi >= 1 && newj <= 3 && newj >= 1 && 
               !(newi == 4 && newj == 1) && !(newi == 4 && newj == 3)){
                   ans += solve(count + 1, newi, newj, n);
               }
        }
        
        return dp[count][i][j] = ans;
    }
    long long getCount(int n) {
        // Your code goes here
        long long ans = 0;
        
        dp.resize(26, vector<vector<long long>>(26, vector<long long>(26, -1)));
        
        for(int i = 1;i <= 4;i++){
            for(int j = 1;j <= 3;j++){
                if(i == 4 && j == 1){
                    continue;
                }
                if(i == 4 && j == 3){
                    continue;
                }
                
                ans += solve(1, i, j, n);
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
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends