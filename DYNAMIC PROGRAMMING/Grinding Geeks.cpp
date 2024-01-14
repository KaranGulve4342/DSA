// GFG POTD 15 JAN 2024

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int solve(int i, int total, vector<vector<int> >&dp, vector<int> &cost){
        if(i == dp.size()){
            return 0;
        }
        
        if(dp[i][total] != -1){
            return dp[i][total];
        }
        
        dp[i][total] = solve(i+1, total, dp, cost);
        
        if(total >= cost[i]){
            dp[i][total] = max(dp[i][total], 1 + solve(i+1, total-cost[i] + ((9 * cost[i]) / 10), dp, cost));
        }
        
        return dp[i][total];
    }
    int max_courses(int n, int total, vector<int> &cost)
    {
        //Code Here
        vector<vector<int> >dp(n, vector<int>(total + 1, -1));
        return solve(0, total, dp, cost);
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob;
        cout<<ob.max_courses(n,k,arr)<<endl;
    }
}
// } Driver Code Ends