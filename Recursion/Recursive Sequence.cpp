// GFG POTD 12 FEB 2024

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int MOD = 1000000007;
    long long solve(int term, int start, int n){
        if(term > n){
            return 0;
        }
        
        long long ans = 1;
        for(int i = 0;i < term;i++){
            ans *= start;
            ans %= MOD;
            start++;
        }
        
        ans += solve(term + 1, start, n);
        ans %= MOD;
        
        return ans;
    }
    long long sequence(int n) {
        
        long long ans = solve(1, 1, n);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends