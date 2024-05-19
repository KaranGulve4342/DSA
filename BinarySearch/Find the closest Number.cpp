// GFG POTD 19TH MAY 2024

//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        // Complete the function
        // Binary Search Approach
        int low = 0, high = n - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (arr[mid] == k) {
                return arr[mid];
            } else if (arr[mid] < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        // At this point, low is the insertion point
        // We need to check the closest between arr[low] and arr[low - 1]
        int closest = arr[0];
        if (low < n && low > 0) {
            int leftDiff = abs(arr[low - 1] - k);
            int rightDiff = abs(arr[low] - k);
            if (leftDiff == rightDiff) {
                closest = max(arr[low - 1], arr[low]);
            } else {
                closest = (leftDiff < rightDiff) ? arr[low - 1] : arr[low];
            }
        } else if (low == 0) {
            closest = arr[low];
        } else if (low == n) {
            closest = arr[n - 1];
        } else if (low < n) {
            closest = arr[low];
        }
        
        return closest;
    } 
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends