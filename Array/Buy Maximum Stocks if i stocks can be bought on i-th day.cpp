// GFG

//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        vector<pair<int, int>> days_prices;

        for (int i = 0; i < n; ++i) {
            days_prices.push_back({price[i], i + 1});
        }

        sort(days_prices.begin(), days_prices.end());

        int ans = 0;
        for (auto x : days_prices) {
            int maxStocks = min(k / x.first, x.second); // Buy minimum of (remaining money / price) and maximum stocks available on the day
            ans += maxStocks;
            k -= maxStocks * x.first;
        }

        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends