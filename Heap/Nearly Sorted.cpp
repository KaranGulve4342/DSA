// GFG POTD 14TH NOVEMBER 2024

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code
        
        int n = arr.size();
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int idx = 0;
        
        for(int i = 0;i < n;i++){
            pq.push(arr[i]);
            
            if(pq.size() > k){
                arr[idx] = pq.top();
                pq.pop();
                idx++;
            }
        }
        
        while(!pq.empty()){
            arr[idx] = pq.top();
            pq.pop();
            idx++;
        }
        
        return;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
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
        obj.nearlySorted(arr, k);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends