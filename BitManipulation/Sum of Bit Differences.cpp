// GFG POTD 29 FEB 2024

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	long long sumBitDifferences(int arr[], int n) {
	    long long ans = 0; // Initialize result

        for(int i = 31;i >= 0;i--){
            long long countZero = 0;
            long long countOne = 0;
            for(int j = 0;j < n;j++){
                if(((1 << i)&arr[j]) > 0){
                    countOne++;
                }
                else{
                    countZero++;
                }
            }
            ans += 2*(countZero*countOne);
        }
        return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.sumBitDifferences(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends