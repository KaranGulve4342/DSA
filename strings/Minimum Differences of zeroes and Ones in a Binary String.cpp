// GFG PRACTICE

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string S)
	{
	    // Your code goes here
	    int count1 = 0;
	    int curr = 0;
	    int maxi = INT_MIN;
	    
	    for(int i = 0;i < S.length();i++){
	        if(S[i] == '0'){
	            curr += 1;
	        }
	        else{
	            curr -= 1;
	            count1++;
	        }
	        
	        curr = max(curr, 0);
	        maxi = max(maxi, curr);
	    }
	    
	    if(count1 == S.length()){
	        return -1;
	    }
	    return maxi;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}

// } Driver Code Ends