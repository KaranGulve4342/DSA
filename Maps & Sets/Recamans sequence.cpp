// GFG POTD 11TH FEB 2024

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> recamanSequence(int n){
        // code here
        vector<int> a(n, 0);
        unordered_set<int> seen;
        for(int i = 1;i < n;i++){
            if((a[i-1] - i) > 0 && seen.find(a[i-1] - i) == seen.end()){
                a[i] = a[i-1] - i;
            }
            else{
                a[i] = a[i-1] + i;
            }
            seen.insert(a[i]);
        }
        
        return a;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends