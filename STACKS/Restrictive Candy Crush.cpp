// GFG PRACTICE

// EVERY PROBLEM IS SOLVABLE

//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    string Reduced_String(int k,string s){
        // Your code goes here
        if(k == 1){
            return "";
        }
        
        stack<pair<char, int>> st;
        
        for(auto ch : s){
            if(!st.empty() && st.top().first == ch){
                st.top().second++;
                if(st.top().second == k){
                    st.pop();
                }
            }
            else{
                st.push({ch, 1});
            }
        }
        
        string ans = "";
        
        while(!st.empty()){
            while(st.top().second--){
                ans += st.top().first;
            }
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }


};

//{ Driver Code Starts.

int main() {
    
    
    int t;cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.Reduced_String(k,s)<<"\n";
        
    }
    
	return 0;
}
// } Driver Code Ends