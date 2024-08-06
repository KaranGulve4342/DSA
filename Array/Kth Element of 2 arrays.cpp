// GFG POTD 7TH AUGUEST 2024

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        int i = 0;
        int j = 0;
        
        int m = arr1.size();
        int n = arr2.size();
        while (i < m && j < n) {
            if (arr1[i] < arr2[j]) {
                i++;
                k--;
                if (k == 0) {
                    return arr1[i - 1];
                }
            } else {
                j++;
                k--;
                if (k == 0) {
                    return arr2[j - 1];
                }
            }
        }
        
        while (i < m) {
            k--;
            if (k == 0) {
                return arr1[i];
            }
            i++;
        }
        
        while (j < n) {
            k--;
            if (k == 0) {
                return arr2[j];
            }
            j++;
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends