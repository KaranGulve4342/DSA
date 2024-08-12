// GFG PRACTICE

//{ Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int transform (string A, string B)
    {
        //code here.
        unordered_map<char, int> umap;
        if(A.length() != B.length()){
            return -1;
        }
        for(auto a : A){
            umap[a]++;
        }
        for(auto b : B){
            if(umap.find(b) != umap.end()){
                umap[b]--;
            }
            if(umap[b] == 0){
                umap.erase(b);
            }
        }
        
        if(umap.size() > 0){
            return -1;
        }
        
        int ans = 0;
        int i = A.length() - 1;
        int j = B.length() - 1;
        
        while(i >= 0 && j >= 0){
            if(A[i] == B[j]){
                i--;
                j--;
            }
            else{
                ans++;
                i--;
            }
        }
        
        return ans;
        
        
    }
};


//{ Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}
// } Driver Code Ends