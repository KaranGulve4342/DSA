// GFG PRACTICE

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    bool check(string& str, int i, int j){
        while(i <= j){
            if(str[i] != str[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int addMinChar(string str){    
        //code here
        int n = str.length();
        int j = n-1;
        
        while(j >= 0){
            if(str[0] == str[j]){
                if(check(str, 0, j)){
                    return n-j-1;
                }
            }
            j--;
        }
        
        return 0;
        
    }
};

//{ Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends