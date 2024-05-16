// GFG POTD

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
    int binarySearch(vector<int>& arr, int low, int high, int target) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target)
                return mid;
            else if (arr[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }

    int findPair(int n, int x, vector<int>& arr) {
        // sort(arr.begin(), arr.end());
        // for (int i = 0; i < n; i++) {
        //     int target1 = arr[i] + x;
        //     int target2 = arr[i] - x;
        //     if (binarySearch(arr, i + 1, n - 1, target1) != -1 || binarySearch(arr, i + 1, n - 1, target2) != -1)
        //         return 1;
        // }
        // return -1;
        
        unordered_set<int> elements;
        
        for(int i = 0;i < n;i++){
            elements.insert(arr[i]);
        }
        
        for (int i = 0; i < n; i++) {
            if (elements.find(arr[i] + x) != elements.end() || elements.find(arr[i] - x) != elements.end()) {
                return 1;
            }
            elements.insert(arr[i]);
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        vector<int> arr(n);
        Array::input(arr, n);

        Solution obj;
        int res = obj.findPair(n, x, arr);

        cout << res << endl;
    }
}

// } Driver Code Ends