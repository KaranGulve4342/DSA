// GFG POTD 22ND JUNE 2024

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string sentence) {

        long long num = 0;
        long long temp = 0;
        int i = 0;
        int j = 0;
        int n = sentence.length();
        
        while(i < n){
            if(sentence[i] >= '0' && sentence[i] < '9'){
                temp = temp*10 + (sentence[i] - '0');
            }
            else if(sentence[i] == '9'){
                temp = 0;
                while(i < n && sentence[i] >= '0' && sentence[i] <= '9'){
                    i++;
                }
            }
            else{
                num = max(num, temp);
                temp = 0;
            }
            i++;
        }
        
        return (num == 0) ? -1 : num;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends