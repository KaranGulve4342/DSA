// GFG 

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int n, int K) 
    { 
        // HashMap to store (cumulative_sum, first_index)
        unordered_map<int, int> cumulative_sum_map;
        int cumulative_sum = 0;
        int max_length = 0;

        for (int i = 0; i < n; ++i) {
            // Update the cumulative sum
            cumulative_sum += A[i];

            // If cumulative sum is equal to K, we have a sub-array starting from index 0
            if (cumulative_sum == K) {
                max_length = i + 1;
            }

            // If (cumulative_sum - K) is found in the map, we found a sub-array with sum K
            if (cumulative_sum_map.find(cumulative_sum - K) != cumulative_sum_map.end()) {
                int length = i - cumulative_sum_map[cumulative_sum - K];
                if (length > max_length) {
                    max_length = length;
                }
            }

            // If the cumulative sum is not in the map, add it
            if (cumulative_sum_map.find(cumulative_sum) == cumulative_sum_map.end()) {
                cumulative_sum_map[cumulative_sum] = i;
            }
        }

        return max_length;
        
        
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends