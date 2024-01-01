// GFG

//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        // int n = S.length() + 1;
        // int incr = 1;
        // int decr = n;
        
        // string ans;
        
        // for(char ch : S){
        //     if(ch == 'I'){
        //         ans += to_string(incr++);
        //     }
        //     else{
        //         ans += to_string(decr--);
        //     }
        // }
        // ans += to_string(incr++);
        // return ans;
        
        int n = S.size() + 1;
        stack<int> stk;
        string result;

        for (int i = 0; i < n; ++i) {
            stk.push(i + 1);
    
            if (i == n - 1 || S[i] == 'I') {
                while (!stk.empty()) {
                    result += std::to_string(stk.top());
                    stk.pop();
                }
            }
        }
    
        return result;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends