// GFG PRACTICE

//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string sum(string s1, string s2){
        if(s1.length() < s2.length()){
            return sum(s2, s1);
        }
        
        string s3 = "";
        
        int sum = 0;
        int carry = 0;
        int rem = 0;
        
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        
        for(int i = 0;i < s2.length();i++){
            int val = s1[i] - '0' + s2[i] - '0' + carry;
            if(val >= 10){
                carry = val/10;
            }
            else{
                carry = 0;
            }
            s3.push_back(val%10 + '0');
        }
        for(int i = s2.length();i < s1.length();i++){
            int val = carry + s1[i] - '0';
            if(val >= 10){
                carry = val/10;
            }
            else{
                carry = 0;
            }
            s3.push_back(val%10 + '0');
        }
        if(carry > 0){
            s3.push_back(carry + '0');
        }
        
        reverse(s3.begin(), s3.end());
        
        return s3;
    }
    bool check(int idx, int len1, int len2, string S){
        string s1 = S.substr(idx, len1);
        string s2 = S.substr(idx + len1, len2);
        
        string s3 = sum(s1, s2);
        
        int n = s3.length();
        
        if(n > S.length() - len1 - len2 - idx){
            return false;
        }
        
        if(s3 == S.substr(idx + len1 + len2, n)){
            if(idx + len1 + len2 + n == S.length()){
                return true;
            }
            
            return check(idx + len1, len2, n, S);
        }
        return false;
    }
    int isSumString(string S){
        // code here 
        int n = S.length();
        
        for(int i = 1;i < n;i++){
            for(int j = 1;i+j < n;j++){
                if(check(0, i, j, S)){
                    return true;
                }
            }
        }
        return false;
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
        cout << ob.isSumString(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends