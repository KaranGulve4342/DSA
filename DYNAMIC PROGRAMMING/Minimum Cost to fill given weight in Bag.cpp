// GFG POTD 28TH MSY 2024

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int solve(int w, vector<int>& cost, vector<int>& dp){
        if(w == 0){
            return 0;
        }
        
        if(dp[w] != -1){
            return dp[w];
        }
        
        int n = cost.size();
        int minCost = INT_MAX;
        
        for(int i = 1;i <= n;i++){
            if(i <= w && cost[i-1] != -1){
                int subAns = solve(w-i, cost, dp);
                
                if(subAns != INT_MAX){
                    minCost = min(minCost, subAns + cost[i-1]);
                }
            }
        }
        
        return dp[w] = minCost;
    }
    int minimumCost(int n, int w, vector<int> &cost) {
        // code here
        // vector<int> dp(w + 1, INT_MAX);
        // dp[0] = 0;
        
        // for (int i = 1; i <= n; i++) {
        //     if (cost[i-1] != -1) { 
        //         for (int j = i; j <= w; j++) {
        //             if (dp[j - i] != INT_MAX) { 
        //                 dp[j] = min(dp[j], dp[j - i] + cost[i-1]);
        //             }
        //         }
        //     }
        // }
        
        // return dp[w] == INT_MAX ? -1 : dp[w];
        
        vector<int> dp(w+1, -1);
        int ans = solve(w, cost, dp);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int w;
        scanf("%d", &w);

        vector<int> cost(n);
        Array::input(cost, n);

        Solution obj;
        int res = obj.minimumCost(n, w, cost);

        cout << res << endl;
    }
}

// } Driver Code Ends