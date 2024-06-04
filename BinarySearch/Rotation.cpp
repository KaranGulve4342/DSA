// GFG

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int nums[], int n) {
	    int lo = 0;
	    int hi = n-1;
	    
	    int ans = INT_MAX;
	    
	    int idx = -1;
	    
	    while(lo <= hi){
	        int mid = lo + (hi - lo)/2;
	        
	        if(nums[lo] <= nums[hi]){
	            if(nums[lo] < ans){
	                idx = lo;
	                ans = nums[lo];
	            }
	            break;
	        }
	        
	        if(nums[lo] <= nums[mid]){
	            if(nums[lo] < ans){
	                idx = lo;
	                ans = nums[lo];
	            }
	            
	            lo = mid + 1;
	        }
	        else{
	            if(nums[mid] < ans){
	                idx = mid;
	                ans = nums[mid];
	            }
	            
	            hi = mid - 1;
	        }
	    }
	    
	    return idx;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends