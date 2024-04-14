// GFG POTD

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,
                              int q) {
        // sort(b.begin(), b.end());
    
        // vector<int> result;
        
        // for (int i = 0; i < query.size(); ++i) {
        //     int count = 0;
        //     // Finding the index in array a
        //     int index = query[i];
        //     // Finding the value of a[index]
        //     int val = a[index];
            
        //     // Counting elements less than or equal to a[index] in array b
        //     for (int j = 0; j < b.size(); ++j) {
        //         if (b[j] <= val) {
        //             count++;
        //         } else {
        //             break;
        //         }
        //     }
            
        //     result.push_back(count);
        // }
        
        // return result;
        sort(b.begin(), b.end());
        vector <int> ans;
        for( auto it : query){
            int count= upper_bound(b.begin(), b.end(),a[it])-b.begin();
            ans.push_back(count);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {

        int n;
        cin >> n;
        vector<int> a, b, ans;
        int input;
        for (int i = 0; i < n; i++) {
            cin >> input;
            a.push_back(input);
        }
        for (int i = 0; i < n; i++) {
            cin >> input;
            b.push_back(input);
        }
        int q;
        cin >> q;
        vector<int> query;
        for (int i = 0; i < q; i++) {
            cin >> input;
            query.push_back(input);
        }
        Solution obj;
        ans = obj.countElements(a, b, n, query, q);
        for (int i = 0; i < q; i++) {
            cout << ans[i] << endl;
        }
    }
    return 0;
}
// } Driver Code Ends