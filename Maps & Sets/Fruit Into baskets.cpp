// GFG => SLIDING WINDOW

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(vector<int> &arr) {
        unordered_map<int, int> umap;
        
        int i = 0, j = 0;
        int maxi = 0;
        
        int n = arr.size();
        
        while(j < n){
            umap[arr[j]]++;
            
            if(umap.size() > 2){
                umap[arr[i]]--;
                
                if(umap[arr[i]] == 0){
                    umap.erase(arr[i]);
                }
                
                i++;
            }
            
            if(umap.size() <= 2){
                maxi = max(maxi, j-i+1);
            }
            
            j++;
        }
        
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.totalFruits(arr);

        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends