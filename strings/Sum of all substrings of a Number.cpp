// GFG POTD

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        int MOD = 1000000007;
        long long sum = 0;
        long long multiplier = 1;
        long long current = 0;
        
        int n = s.length();
        for(int i = n - 1; i >= 0; i--) {
            current = (current + (s[i] - '0') * multiplier) % MOD;
            sum = (sum + current) % MOD;
            multiplier = (multiplier * 10 + 1) % MOD;
        }
        
        return sum;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}

// } Driver Code Ends