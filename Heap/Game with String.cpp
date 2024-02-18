// GFG POTD 19 FEB 2024

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
            
        int n = s.length();
        unordered_map<char, int> umap;
        
        for(auto ch : s){
            umap[ch]++;
        }
        
        priority_queue<int> pq;
        for(auto x : umap){
            pq.push(x.second);
        }
        
        while(k-- && pq.size() > 0){
            int diff = pq.top() - 1;
            pq.pop();
            pq.push(diff);
        }
        int ans = 0;
        while(pq.size() > 0){
            int p = pq.top();
            pq.pop();
            ans += p*p;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends