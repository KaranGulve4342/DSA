// GFG PRACTICE

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    bool isValid(vector<int>& need, vector<int>& have) {
        for (int i = 0; i < 26; i++) {
            if (need[i] > have[i]) {
                return false;
            }
        }
        return true;
    }

    string smallestWindow (string s, string p) {
        // Your code here
        vector<int> need(26, 0);
        vector<int> have(26, 0);
        
        for (auto ch : p) {
            need[ch - 'a']++;
        }
        
        int j = 0;
        int n = s.length();
        
        int miniLen = n + 1;
        int start = -1;
        
        for (int i = 0; i < n; i++) {
            have[s[i] - 'a']++;
            
            // Shrink the window if it's valid
            while (j <= i && isValid(need, have)) {
                int currlen = i - j + 1;
                
                if (currlen < miniLen) {
                    miniLen = currlen;
                    start = j;
                }
                
                // Decrement the count of the character as we move the left pointer
                have[s[j] - 'a']--;
                j++;
            }
        }
        
        if (start == -1) {
            return "-1"; // No valid window found
        }
        
        return s.substr(start, miniLen);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends