// GFG CONTEST 3 MARCH 2024

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int luckyString(int N, string S) {
        // code here
        for(int i = 0; i < N-1;i++){
            if(S[i] == 'A' && S[i+1] == 'A'){
                return 2;
            }
        }
        for(int i = 0; i < N-2;i++){
            if(S[i] == 'A' && S[i+2] == 'A'){
                return 3;
            }
        }
        for(int i = 0; i < N-3;i++){
            if(S[i] == 'A' && S[i+3] == 'A' && S[i+1] != S[i+2]){
                return 4;
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int N;
        cin>>N;
        
        
        string S;
        cin>>S;
        
        Solution obj;
        int res = obj.luckyString(N, S);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends