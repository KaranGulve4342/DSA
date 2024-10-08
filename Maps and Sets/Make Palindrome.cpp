// GFG PRACTICE

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool makePalindrome(int n,vector<string> &arr){
        // Code here
        unordered_map<string, int> umap;
        
        for(auto str : arr){
            umap[str]++;
        }
        int count = 0;
        
        for(auto x : umap){
            string str = x.first;
            
            string rev = str;
            reverse(rev.begin(), rev.end());
            
            if(str == rev){
                if(umap[str] % 2 != 0){
                    count++;
                }
            }
            else{
                if(umap[str] != umap[rev]){
                    return false;
                }
            }
        }
        
        return count <= 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends