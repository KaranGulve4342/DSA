
// GFG POTD 29 JAN 2024

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
// 	int TotalCount(string str){
// 	    // Code here
// 	}
	
	int dp[100][9*100 + 1];

    int countGroups(int position, int previous_sum, int length, string num){
        if(position == length){
            return 1;
        }
        if(dp[position][previous_sum] != -1){
            return dp[position][previous_sum];
        }

        dp[position][previous_sum] = 0;
        int res = 0;
        int sum = 0;

        for(int i = position;i < length;i++){
            sum += (num[i] - '0');
            if(sum >= previous_sum){
                res += countGroups(i+1, sum, length, num);
            }
        }
        dp[position][previous_sum] = res;
        return res;
    }

    int TotalCount(string num){
        memset(dp, -1, sizeof(dp));
        int len = num.size();
        int x = countGroups(0, 0, len, num);
        return x;
    }

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends