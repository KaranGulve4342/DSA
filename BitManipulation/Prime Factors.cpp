// GFG 

//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
	public:
	vector<int>AllPrimeFactors(int N) {
	    vector<int> ans;
        
        // Check for smallest prime factor (2)
        if (N % 2 == 0) {
            ans.push_back(2);
            while (N % 2 == 0) {
                N /= 2;
            }
        }
        
        // Check for all odd factors up to sqrt(N)
        for (int i = 3; i * i <= N; i += 2) {
            if (N % i == 0) {
                ans.push_back(i);
                while (N % i == 0) {
                    N /= i;
                }
            }
        }
        
        // If N is still greater than 2, then N is a prime number
        if (N > 2) {
            ans.push_back(N);
        }
        
        return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.AllPrimeFactors(N);
		for(auto i: ans)
			cout << i <<" ";
		cout <<"\n";
	}  
	return 0;
}
// } Driver Code Ends