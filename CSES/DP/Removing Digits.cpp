// // CSES PROBLEM SET

// // EVERY PROBLEM IS SOLVABLE

// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// int solve(int n, vector<int>& dp){
//     if(n == 0){
//         return 0;
//     }

//     if(dp[n] != -1){
//         return dp[n];
//     }

//     int ans = 1e9;

//     int temp = n;

//     while(temp){
//         int d = temp % 10;

//         ans = min(ans, 1 + solve(n-d, dp));

//         temp /= 10;
//     }

//     return dp[n] = ans;
// }

// signed main(){
//     int n;
//     cin >> n;

//     vector<int> dp(n+1, -1);
//     // dp[0] = 0;

//     // for(int i = 1;i <= n;i++){
//     //     int temp = i;

//     //     while(temp){
//     //         int d = temp%10;
//     //         dp[i] = min(dp[i], 1 + dp[i-d]);
//     //         temp /= 10;
//     //     }
//     // }

//     // cout << dp[n] << endl;

//     cout<<solve(n, dp)<<endl;

//     return 0;

// }

// CSES PROBLEM SET

// EVERY PROBLEM IS SOLVABLE

#include <bits/stdc++.h>
using namespace std;

#define int long long

int solve(int n, vector<int>& dp) {
    if (n == 0) return 0;
    if (dp[n] != -1) return dp[n];

    int min_steps = 1e9;
    int temp = n;

    while (temp) {
        int d = temp % 10;
        if (d != 0) {
            min_steps = min(min_steps, 1 + solve(n - d, dp));
        }
        temp /= 10;
    }

    return dp[n] = min_steps;
}

signed main() {
    int n;
    cin >> n;

    vector<int> dp(n + 1, -1);

    cout << solve(n, dp) << endl;

    return 0;
}