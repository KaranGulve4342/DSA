// GFG POTD

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here.
        int n = arr.size();
        
        unordered_map<int, int> umap;
        
        int i = 0;
        
        vector<int> ans;
        
        for(i = 0;i < k;i++){
            umap[arr[i]]++;
        }
        
        ans.push_back(umap.size());
        
        while(i < n){
            umap[arr[i]]++;
            umap[arr[i-k]]--;
            
            if(umap[arr[i-k]]==0){
                umap.erase(arr[i-k]);
            }
            
            ans.push_back(umap.size());
            i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends