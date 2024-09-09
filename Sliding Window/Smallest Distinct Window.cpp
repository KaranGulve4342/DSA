// GFG PRACTICE

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here   
        unordered_set<char> st;
        for(auto ch : str){
            st.insert(ch);
        }
        
        int total = st.size();
        
        unordered_map<char, int> umap;
        int left = 0;
        int right = 0;
        int n = str.length();
        
        int minLen = n;
        
        int uniqueCount = 0;
        
        while(right < n){
            umap[str[right]]++;
            
            if (umap[str[right]] == 1) {
                uniqueCount++;
            }

            while (uniqueCount == total) {
                minLen = min(minLen, right - left + 1);
                
                umap[str[left]]--;
                
                if (umap[str[left]] == 0) {
                    uniqueCount--;
                }
                
                left++;
            }
            right++;
        }
        
        return minLen;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends