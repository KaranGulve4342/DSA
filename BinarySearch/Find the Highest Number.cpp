// GFG POTD 18TH MAY 2024

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int findPeakElement(vector<int>& arr) 
    {
        // Code here.
        int n = arr.size();
        int low = 0;
        int high = n-1;
        
        while(low < high){
            int mid = low + (high - low)/2;
            
            if (arr[mid] > arr[mid + 1]) {
                // Peak element is in the left half
                high = mid;
            } else {
                // Peak element is in the right half
                low = mid + 1;
            }
        }
        
        return arr[low];
    }
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	vector<int>a(n);
    	for(int i = 0; i < n; i++)
    		cin>>a[i];
    	Solution ob;
    	int ans = ob.findPeakElement(a);
    	cout << ans << "\n";
    }
	return 0;
}


// } Driver Code Ends