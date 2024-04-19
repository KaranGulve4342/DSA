// GFG POTD 

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	public:
	vector<int> findMissing(int a[], int b[], int n, int m) 
	{ 
	    // Your code goes here
	    // Create a set to store elements of array b
    unordered_set<int> bSet;
    for (int i = 0; i < m; i++) {
        bSet.insert(b[i]);
    }
    
    // Iterate through array a and check if each element is present in array b
    vector<int> missingElements;
    for (int i = 0; i < n; i++) {
        if (bSet.find(a[i]) == bSet.end()) {
            // If element from array a is not present in array b, add it to the missing elements vector
            missingElements.push_back(a[i]);
        }
    }
    
    return missingElements;
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
        cin>>n;
        int m;
        cin>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
        cin>>a[i];
        for(int i=0;i<m;i++)
        cin >> b[i];
        vector<int> ans;
        

        Solution ob;
        ans=ob.findMissing(a,b,n,m);
        for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
	    
        
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends