// GFG PRACTICE

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string s)
{
    // your code here
    int n = s.length();
    unordered_map<char, int> umap;
    
    
    int left = 0;
    int right = 0;
    
    int maxi = 0;
    
    while(right < n){
        umap[s[right]]++;
        
        while (umap[s[right]] > 1) {
            
            umap[s[left]]--;
            
            if (umap[s[left]] == 0) {
                umap.erase(s[left]);
            }
            
            left++;
        }
        
        maxi = max(maxi, right - left + 1);
        right++;
    }
    
    return maxi;
}