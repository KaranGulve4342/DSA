// GFG PRACTICE

// EVERY PROBLEM IS SOLVABLE

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int numberOfSubsequences(string S, string W){
        // code here 
        int m = S.length();
        int n = W.length();
        
        int count = 0;
        
        for(int i = 0;i < m;i++){
            int k = 0;
            for(int j = 0;j < m;j++){
                if(S[j] == W[k]){
                    S[j] = '?';
                    k++;
                    if(k == n){
                        break;
                    }
                }
            }
            if(k == n){
                count++;
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    }
    return 0; 
} 


// } Driver Code Ends