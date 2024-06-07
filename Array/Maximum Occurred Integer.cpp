// GFG POTD 7TH JUNE 2024

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // l and r are input array
    // maxx : maximum in r[]
    // n: size of array
    // arr[] : declared globally with size equal to maximum in l[] and r[]
    // Function to find the maximum occurred integer in all ranges.
    int maxOccured(int n, int l[], int r[], int maxx) {

        // Your code here
        // unordered_map<int, int> umap;
        
        // for(int i = 0;i < n;i++){
        //     for(int j = l[i];j <= r[i];j++){
        //         umap[j]++;
        //     }
        // }
        
        // int maxFreq = 0;
        // int maxi = -1;
        
        // for(auto x : umap){
        //     if(x.second > maxFreq){
        //         maxi = x.first;
        //         maxFreq = x.second;
        //     }
        //     else if(x.second == maxFreq){
        //         if(maxi > x.first){
        //             maxi = x.first;
        //         }
        //     }
        // }
        
        // return maxi;
        
        // Initialize a frequency array
        vector<int> freq(maxx + 2, 0);

        // Mark the start and end points in the frequency array
        for (int i = 0; i < n; ++i) {
            freq[l[i]]++;
            if (r[i] + 1 <= maxx) {
                freq[r[i] + 1]--;
            }
        }

        // Compute the prefix sum array
        int maxFreq = 0;
        int maxOccuredElement = 0;
        for (int i = 1; i <= maxx; ++i) {
            freq[i] += freq[i - 1];
            if (freq[i] > maxFreq) {
                maxFreq = freq[i];
                maxOccuredElement = i;
            }
        }

        return maxOccuredElement;
    }
};


//{ Driver Code Starts.

int main() {

    int t;

    // taking testcases
    cin >> t;

    while (t--) {
        int n;

        // taking size of array
        cin >> n;
        int l[n];
        int r[n];

        // adding elements to array L
        for (int i = 0; i < n; i++) {
            cin >> l[i];
        }

        int maxx = 0;

        // adding elements to array R
        for (int i = 0; i < n; i++) {

            cin >> r[i];
            if (r[i] > maxx) {
                maxx = r[i];
            }
        }
        Solution ob;

        // calling maxOccured() function
        cout << ob.maxOccured(n, l, r, maxx) << endl;
    }

    return 0;
}
// } Driver Code Ends