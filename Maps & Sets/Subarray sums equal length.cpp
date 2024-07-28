// GFG CONTEST 28TH JULY 2024

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int longestSubarray(int n, vector<int> &arr) {
        // code here
        unordered_map<long long, int> umap;
        umap[0] = -1;
        int ans = INT_MIN;
        
        long long sum = 0;
        
        for(int i = 0;i < n;i++){
            sum += arr[i];
            
            if(sum == i+1){
                ans = max(ans, i+1);
            }
            
            long long rem = sum - (i+1);
            
            if(umap.find(rem) != umap.end()){
                ans = max(ans, i - umap[rem]);
            }
            
            if(umap.find(rem) == umap.end()){
                umap[rem] = i;
            }
        }
        
        return ans == INT_MIN ? -1 : ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> arr(n);
        Array::input(arr, n);

        Solution obj;
        int res = obj.longestSubarray(n, arr);

        cout << res << endl;
    }
}

// } Driver Code Ends