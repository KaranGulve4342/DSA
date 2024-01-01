// GFG

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    int i,j;
	    int max = 0;
	    int msis[n];
	    
	    for(i = 0;i < n;i++){
	        msis[i] = arr[i];
	    }
	    
	    for(int i = 0;i < n;i++){
	        for(int j = 0;j < i;j++){
	            if(arr[i] > arr[j] && msis[i] < msis[j] + arr[i]){
	                msis[i] = msis[j] + arr[i];
	            }
	        }
	    }
	    for(int i = 0;i < n;i++){
	        if(max < msis[i]){
	            max = msis[i];
	        }
	    }
	    
	    return max;
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
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends

/*
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{ 
	   vector<int> dp(n+1);
	   int i, j;
	   int max = 0;
	   
	   for(i = 0;i < n;i++){
	       dp[i] = arr[i];
	       for(j = 0;j < i;j++){
	           if(arr[i] > arr[j]){
	               dp[i] = std::max(dp[i], dp[j] + arr[i]);
	           }
	       }
	   }
	   for(int i = 0;i < n;i++){
	       if(max < dp[i]){
	           max = dp[i];
	       }
	   }
	   
	   return max;
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
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends
*/