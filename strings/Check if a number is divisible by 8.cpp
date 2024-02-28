// GFG POTD 28 FEB 2024

//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int DivisibleByEight(string s){
        //code here
        int n = s.size();
        
        // If the string length is less than 3, we can directly check if the number is divisible by 8
        if(n < 3) {
            int num = stoi(s);
            if(num % 8 == 0)
                return 1;
            else
                return -1;
        }
        
        // Otherwise, check the last three digits
        int last_three_digits = stoi(s.substr(n - 3));
        if(last_three_digits % 8 == 0)
            return 1;
        else
            return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends