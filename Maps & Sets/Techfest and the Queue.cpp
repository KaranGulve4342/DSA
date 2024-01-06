// GFG POTD 6 Jan'24

//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
	unordered_map<int, int> primeFactors(int n) {
        unordered_map<int, int> factors;
        while (n % 2 == 0) {
            factors[2]++;
            n = n / 2;
        }
    
        for (int i = 3; i <= sqrt(n); i = i + 2) {
            while (n % i == 0) {
                factors[i]++;
                n = n / i;
            }
        }
    
        if (n > 2) {
            factors[n]++;
        }

        return factors;
    }
    
    int sumOfPrimePowers(int n) {
        unordered_map<int, int> factors = primeFactors(n);
        int primeFactorsSum = 0;
        for (auto it = factors.begin(); it != factors.end(); it++) {
            primeFactorsSum += it->second;
        }
        return primeFactorsSum;
    }
    
    int sumOfPowers(int a, int b) {
        int totalSum = 0;
        for (int i = a; i <= b; i++) {
            totalSum += sumOfPrimePowers(i);
        }
        return totalSum;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends