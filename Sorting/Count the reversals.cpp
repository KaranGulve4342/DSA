// GFG PRACTICE

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s){
    // your code here
    int n = s.length();
    
    if(n&1){
        return -1;
    }
    
    int c = 0;
    int c1 = 0;
    
    stack<int> st;
    
    for(int i = 0;i < n;i++){
        if(s[i] == '{'){
            st.push(s[i]);
            c1++;
        }
        else if(s[i] == '}' && !st.empty() && st.top() == '{'){
            st.pop();
            c1--;
        }
        else{
            c++;
        }
    }
    
    if(c&1){
        c = c/2 + 1;
    }
    else{
        c = c/2;
    }
    
    if(c1&1){
        c1 = c1/2 + 1;
    }
    else{
        c1 = c1/2;
    }
    
    return c + c1;
}