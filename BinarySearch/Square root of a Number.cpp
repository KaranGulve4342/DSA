//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Edge case for x = 0 or x = 1
        if (x == 0 || x == 1) 
            return x;

        long long lo = 1, hi = x, ans = 0;
        
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            long long val = mid * mid;
            
            if (val == x) 
                return mid;
            else if (val < x) {
                lo = mid + 1;
                ans = mid;  // Store the result and keep trying for a larger value
            } else {
                hi = mid - 1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends