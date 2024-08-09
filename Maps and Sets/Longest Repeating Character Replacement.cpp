// LEETCODE 424

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int characterReplacement(string s, int K) {
        // code here
        int n = s.length();
        int left = 0;
        int right = 0;
        
        int maxi = 0;
        
        unordered_map<char, int> umap;
        
        while(right < n){
            umap[s[right]]++;
            
            int maxCount = 0;
            
            for(auto x : umap){
                maxCount = max(maxCount, x.second);
            }
            
            int len = right - left + 1;
            
            if(len - maxCount > K){
                umap[s[left]]--;
                left++;
            }
            
            maxi = max(maxi, right - left + 1);
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
        string S;
        cin >> S;
        int K;
        cin >> K;

        Solution obj;
        cout << obj.characterReplacement(S, K) << endl;
    }
    return 0;
}
// } Driver Code Ends