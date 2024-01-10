// GFG POTD 10 Jan'24

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    
	    unordered_map<int, int> prefixSumCount;
        int maxLength = 0;
        int prefixSum = 0;
        int sum = 0;
    
        for (int i = 0; i < n; ++i) {
            sum += arr[i];
            prefixSum = ((sum % k) + k) % k;
            if (prefixSum == 0)
                maxLength = i + 1;
            else if (prefixSumCount.find(prefixSum) != prefixSumCount.end())
                maxLength = max(maxLength, i - prefixSumCount[prefixSum]);
            else
                prefixSumCount[prefixSum] = i;
        }
        return maxLength;
	}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends