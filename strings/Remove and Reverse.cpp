// GFG

//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string S) {
        // code here
        int n = S.length();
        
        int i = 0;
        int j = n-1;
        
        unordered_map<char, int> umap;
        
        for(auto ch : S){
            umap[ch]++;
        }
        
        bool flag = true;
        
        while(i <= j){
            if(flag == true){
                if(umap[S[i]] > 1){
                    umap[S[i]]--;
                    S[i] = '0';
                    flag = false;
                }
                i++;
            }
            else{
                if(umap[S[j]] > 1){
                    umap[S[j]]--;
                    S[j] = '0';
                    flag = true;
                }
                j--;
            }
        }
         string ans = "" ;
            for(auto it : S ){
                if( it != '0' )
                ans+=it ;
            }
        if( flag ) return ans;
        reverse(ans.begin(),ans.end()) ;
        return ans ;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends