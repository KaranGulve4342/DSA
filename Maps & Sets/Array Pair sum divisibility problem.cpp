// GFG POTD 1 Jan'2024

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        unordered_map<int, int> freq;

        for (int num : nums) {
            int remainder = num % k;
            freq[remainder]++;
        }
    
        for (int num : nums) {
            int remainder = num % k;
            int complement = (k - remainder) % k;
    
            if (2 * remainder == k) {
                if (freq[remainder] % 2 != 0) {
                    return false;
                }
            } else if (remainder == 0) {
                if (freq[remainder] % 2 != 0) {
                    return false;
                }
            } else if (freq[remainder] != freq[complement]) {
                return false;
            }
        }
    
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends