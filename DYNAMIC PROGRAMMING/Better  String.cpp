// GFG POTD

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int distinctSubseq(string str){
        int count = 1;
        
        unordered_map<char, int> umap;
        
        for(int i = 0;i < str.length();i++){
            int newCount = 2*count;
            
            if(umap.find(str[i]) != umap.end()){
                newCount -= umap[str[i]];
            }
            
            umap[str[i]] = count;
            count = newCount;
        }
        
        return count;
    }
    string betterString(string str1, string str2) {
        // code here
        
        int ans1 = distinctSubseq(str1);
        int ans2 = distinctSubseq(str2);
        
        return ans2 > ans1 ? str2 : str1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends