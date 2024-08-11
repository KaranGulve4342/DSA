// GFG PRACTICE

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string encode(string s) {
        // code here
        string ans = "";
        int n = s.length();
        for(int i = 0;i < n;i++){
            int count = 0;
            ans += s[i];
            while(s[i] == s[i+1]){
                count++;
                i++;
            }
            
            if(count >= 0){
                ans += to_string(count+1);
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        string s;
        getline(cin,s);
        
        Solution obj;
        string res = obj.encode(s);
        
        cout<<res<<"\n";
        
    }
}

// } Driver Code Ends