// GFG PRACTICE

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool solve(vector<int>& arr, int sum, int idx, vector<vector<int>> &dp){
        if(sum == 0){
            return true;
        }
        
        if(idx == 0){
            return false;
        }
        
        if(dp[sum][idx] != -1){
            return dp[sum][idx];
        }
        
        bool take = false;
        
        if(arr[idx - 1] <= sum){
            take = solve(arr, sum - arr[idx-1], idx-1, dp);
        }
        
        bool notTake = solve(arr, sum - 0, idx - 1, dp);
        
        return dp[sum][idx] = take || notTake;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<int>> dp(sum + 2, vector<int>(n+1, -1));
        
        return solve(arr, sum, n, dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends