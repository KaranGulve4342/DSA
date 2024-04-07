// GFG POTD

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    long long maximumAmount(int n, int arr[]) {
        vector<vector<long long>> memo(n+1, vector<long long>(n+1, -2));
        for(auto& x : memo) {
            fill(x.begin(), x.end(), -2);
        }
        return fun(0, n-1, arr, memo);
    }

    long long fun(int i, int j, int arr[], vector<vector<long long>>& memo) {
        if(i > j) return 0;
        
        if(i == j)
            return arr[i];
        
        if(memo[i][j] != -2) return memo[i][j];
        
        long long x = arr[i] + min(fun(i+2, j, arr, memo), fun(i+1, j-1, arr, memo));
        
        long long y = arr[j] + min(fun(i, j-2, arr, memo), fun(i+1, j-1, arr, memo));
        
        return memo[i][j] = max(x, y);
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
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(n,a)<<endl;
	}
	return 0;
}
// } Driver Code Ends