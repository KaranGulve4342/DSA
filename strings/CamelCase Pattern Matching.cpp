// GFG PRACTICE

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool matchPattern(string &word, string &Pattern){
        string patternInWord = "";
        
        for(auto ch : word){
            if(isupper(ch)){
                patternInWord += ch;
            }
            if(patternInWord == Pattern){
                return true;
            }
        }
        
        return patternInWord == Pattern;
    }
    vector<string> CamelCase(int N, vector<string> Dictionary, string Pattern) {
        // code here
        vector<string> ans;
        
        for(auto word : Dictionary){
            if(matchPattern(word, Pattern)){
                ans.push_back(word);
            }
        }
        
        if(ans.empty()){
            return {"-1"};
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends