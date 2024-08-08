// GFG PRACTICE

// EVERY PROBELM IS SOLVABLE

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        
        int n = s.length();
        
        int left = 0;
        int right = 0;
        int maxi = -1;
        
        unordered_map<char, int> umap;
        
        while(right < n){
            umap[s[right]]++;
            
            while(umap.size() > k){
                umap[s[left]]--;
                
                if(umap[s[left]] == 0){
                    umap.erase(s[left]);
                }
                left++;
            }
            
            if(umap.size() == k){
                maxi = max(maxi, right - left + 1);
            }
            
            right++;
        }
        
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends