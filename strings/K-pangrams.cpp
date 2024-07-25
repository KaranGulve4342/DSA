// GFG POTD 26TH JULY 2024

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool kPangram(string str, int k) {
        // code here
        int n = str.length();
        vector<int> arr(26, 0);
        
        int count = 0;
        
        for(int i = 0;i < n;i++){
            if(isalpha(str[i])){
                count++;
                arr[str[i] - 'a']++;
            }
        }
        
        if(count < 26){
            return false;
        }
        int spaceCount = 0;
        for(int j = 0;j < 26;j++){
            if(arr[j] == 0){
                spaceCount++;
            }
        }
        
        if(spaceCount == 0){
            return true;
        }
        
        if(k >= spaceCount){
            return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends