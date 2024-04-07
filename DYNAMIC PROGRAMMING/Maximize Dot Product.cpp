// GFG POTD

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		
	public:
	int maxDotProduct(int n, int m, int a[], int b[]) 
	{ 
// 		// Your code goes here
// 		priority_queue<int> pq1;
// 		priority_queue<int> pq2;
// 		for(int i = 0;i < n;i++){
// 		    pq1.push(a[i]);
// 		}
// 		for(int i = 0;i < m;i++){
// 		    pq2.push(b[i]);
// 		}
		
// 		int ans = 0;
// 		while(!pq2.empty()){
// 		    int a = pq1.top();
// 		    pq1.pop();
// 		    int b = pq2.top();
// 		    pq2.pop();
		    
// 		    int product = a*b;
// 		    ans += product;
// 		}
// 		return ans;

        int dp[m+1][n+1];
        memset(dp, 0, sizeof(dp));
        for(int i =1;i <= m;i++){
            for(int j = i;j <= n;j++){
                dp[i][j] = max((dp[i-1][j-1] + (a[j-1] * b[i-1])), dp[i][j-1]);
            }
        }
        return dp[m][n];
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n], b[m];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

        for(int i = 0; i < m; i++)
        	cin >> b[i];

       

	    Solution ob;
	    cout << ob.maxDotProduct(n, m, a, b) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends