// GFG

//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    int count = 0;
	    int start = -1;
	    int end = 0;
	    
	    int lo = 0;
	    int hi = n-1;
	    
	    while(lo <= hi){
	        int mid = lo + (hi - lo)/2;
	        
	        if(arr[mid] == x){
	            start = mid;
	            end = mid;
	            count = 1;
	            
	            while(start > 0 && arr[start - 1] == x){
	                count++;
	                start--;
	            }
	            while(end < n-1 && arr[end+1] == x){
	                count++;
	                end++;
	            }
	            
	            return count;
	        }
	        else if(arr[mid] < x){
	            lo = mid+1;
	        }
	        else{
	            hi = mid - 1;
	        }
	    }
	    
	    return count;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends