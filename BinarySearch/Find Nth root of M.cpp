// GFG PRACTICE

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int solve(int mid, int n, int m){
        long long ans = 1;
        for(int i = 1; i <= n; i++){
            ans *= mid;
            if(ans > m){
                return 2;
            }
        }
        if(ans == m){
            return 1;
        }
        return 0;
    }

    int NthRoot(int n, int m)
    {
        int lo = 1;
        int hi = m;
        
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            int result = solve(mid, n, m);
            if(result == 1){
                return mid;
            }
            else if(result == 0){
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        
        return -1;
    }  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends