// GFG PRACTICE

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
    bool solve(int idx, int target, int arr[], vector<vector<int>>& dp) {
        if (target == 0) {
            return true;
        }
        
        if (idx == 0) {
            return arr[0] == target;
        }
        
        if (dp[idx][target] != -1) {
            return dp[idx][target];
        }
        
        bool notTake = solve(idx - 1, target, arr, dp);
        
        bool take = false;
        
        if (arr[idx] <= target) {
            take = solve(idx - 1, target - arr[idx], arr, dp);
        }
        
        return dp[idx][target] = take | notTake;
    }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum = 0;
	    
        if (n == 1) {
            return arr[0]; // The minimum difference is the value itself if there's only one element
        }
	    
	    for(int i = 0;i < n;i++){
	        sum += arr[i];
	    }
	    
	    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
	    
	    for(int i = 0;i <= sum/2;i++){
	        solve(n-1, i, arr, dp);
	    }
	    
	    
	    int minDiff = INT_MAX;
	    
	    for(int s1 = 0;s1 <= sum/2;s1++){
	        if(dp[n-1][s1]){
	            int s2 = sum - s1;
	            
	            minDiff = min(minDiff, abs(s2 - s1));
	        }
	    }
	    
	    return minDiff;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends