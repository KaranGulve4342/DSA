// CSES PROBLEM SET

#include <bits/stdc++.h>
using namespace std;

#define int long long

#define MOD 1000000007

int countWays(int i, vector<int>& dp){
    if(i == 0){
        return 1;
    }

    if(i < 0){
        return 0;
    }

    if(dp[i] != -1){
        return dp[i];
    }
    dp[i] = 0;
    for(int j = 1;j <= 6;j++){
        dp[i] = (dp[i] + countWays(i-j, dp)) % MOD;
    }

    return dp[i];
}

signed main(){
    int n;
    cin >> n;

    // vector<int> dp(n+1, 0);
    // dp[0] = 1;

    // for(int i = 1;i <= n;i++){
    //     for(int j = 1;j <= 6;j++){
    //         if(i-j >= 0){
    //             dp[i] = (dp[i] + dp[i-j]) % MOD;
    //         }
    //     }
    // }

    // cout << dp[n] % MOD << endl;

    vector<int> dp(n+1, -1);

    cout<<countWays(n, dp) % MOD<<endl;

    return 0;
}