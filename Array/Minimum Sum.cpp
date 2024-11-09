// GFG POTD

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
        int n = arr.size();
        if(n&1) arr.push_back(0);
        sort(arr.rbegin(),arr.rend());
        string a;
        int i = 0;
        int car = 0;
        while(i<n){
            int x = arr[i++];
            int y = arr[i++];
            a.push_back((x+y+car)%10+'0');
            car = (x+y+car)/10;
        }
        while(a.back()=='0') a.pop_back();
        if(car) a.push_back('1');
        return string(a.rbegin(),a.rend());
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends