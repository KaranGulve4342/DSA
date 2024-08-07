// EVERY PROBLEM IS SOLVABLE

#include <bits/stdc++.h>
using namespace std;

#define int long long

int solve(int n){
    if(n == 0) return 0;
    return n/5 + solve(n/5);
}

signed main(){
    int n;
    cin >> n;

    // vector<int> dp(n+1, 0);
    // dp[0] = 1;
    // dp[1] = 1;


    // for(int i = 2;i <= n;i++){
    //     dp[i] = i * dp[i-1];
    // }

    // int ans = dp[n];

    // int cnt = 0;

    // while(ans % 10 == 0){
    //     cnt++;
    //     ans /= 10;
    // }

    // cout << cnt << endl;

    // return 0;

    cout<<solve(n)<<endl;
    return 0;


}
