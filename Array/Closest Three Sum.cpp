// GFG POTD 9TH JULY 2024

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        
        int closestSum = INT_MAX;
        int minDiff = INT_MAX;
        
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int currentSum = arr[i] + arr[left] + arr[right];
                int currentDiff = abs(currentSum - target);
                
                if (currentDiff < minDiff) {
                    minDiff = currentDiff;
                    closestSum = currentSum;
                } 
                else if (currentDiff == minDiff) {
                    closestSum = max(closestSum, currentSum);
                }
                
                if (currentSum < target) {
                    left++;
                } 
                else {
                    right--;
                }
            }
        }
        
        return closestSum;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends