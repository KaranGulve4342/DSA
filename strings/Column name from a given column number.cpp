// GFG POTD 3rd Oct. 2023

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
        string ans = "";
        while(n > 0){
            long long rem = (n-1)%26;
            char ch = 'A' + rem;
            ans = ch + ans;
            n = (n-1)/26;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends