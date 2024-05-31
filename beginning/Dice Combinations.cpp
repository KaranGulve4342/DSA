// CSES DP PROBLEM

#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

vector<int> dp;

int solve(int n){
    if(n < 0){
        return 0;
    }

    if(n == 0){
        return 1;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    for(int i = 1;i <= 6;i++){
        dp[n] = (dp[n] + (solve(n-i) % mod)) % mod;
    }

    return dp[n] %= mod;
}

int main(){
    int n;
    cin>>n;

    dp.resize(n+1, -1);

    cout<<solve(n)<<endl;
    return 0;
}