// GFG PRACTICE

//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string findSum(string X, string Y) {
        // Your code goes here
        int m = X.length();
        int n = Y.length();
        
        int carry = 0;
        string sum = "";
        
        int i = m-1;
        int j = n-1;
        
        while(i >= 0 && j >= 0){
            int s = (X[i] - '0') + (Y[j] - '0') + carry;
            string temp = to_string(s);
            if(s > 9){
                temp = to_string(s%10);
            }
            carry = s/10;
            
            sum = temp + sum;
            
            i--;
            j--;
        }
        
        while(i >= 0){
            int x = (X[i] - '0') + carry;
            
            if(x > 9){
                carry = x/10;
                x = x%10;
            }
            else{
                carry = 0;
            }
            
            i--;
            sum = to_string(x) + sum;
        }
        
        while(j >= 0){
            int y = (Y[j] - '0') + carry;
            
            if(y > 9){
                carry = y/10;
                y = y%10;
            }
            else{
                carry = 0;
            }
            
            j--;
            sum = to_string(y) + sum;
        }
        
        while(carry){
            string ch = to_string(carry%10);
            carry /= 10;
            sum = ch + sum;
        }
        
        reverse(sum.begin(), sum.end());
        
        while(sum.back() == '0'){
            sum.pop_back();
        }
        
        if(sum == ""){
            return "0";
        }
        
        reverse(sum.begin(), sum.end());
        
        return sum;
        
        
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.findSum(x, y) << "\n";
    }

    return 0;
}
// } Driver Code Ends