// GFG PRACTICE

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string addStrings(string num1, string num2) {
        
        string result = "";
        int carry = 0;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
    
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0){
                sum += num1[i] - '0';
                i--;
            }
            if (j >= 0){
                sum += num2[j] - '0';
                j--;
            }
            result += (sum % 10) + '0';    
            carry = sum / 10;   
        }
        reverse(result.begin(), result.end());   
        int k = 0;
        while(result[0] == '0'){
            result.erase(result.begin());
        }
        
        if(result.empty()){
            return "0";
        }
        return result;
    }
    
    string solve(int arr[], int n) {
        sort(arr, arr + n);
        
        string num1 = "";
        string num2 = "";
        
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0){
                num1 += to_string(arr[i]);
            }
            else{
                num2 += to_string(arr[i]);
            }
        }
        
        return addStrings(num1, num2);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends