// ## Codeforces

#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &a){

    const int MOD = 1e9 + 7;
    vector<int> dp(5009);
    dp[0] = 1;

    for(int i = 0;i < n;i++){
        for(int j = 5000;j >= 0;j--){
            if(j + a[i] <= 5000){
                dp[j + a[i]] = (dp[j + a[i]] + dp[j]) % MOD;
            }
        }
    }
    int result = 0;
    for(int i = 1;i <= 5000;i++){
        result = (result + dp[i]) % MOD;
    }
    return result;

}

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }

    cout<<solve(n, a)<<endl;
    return 0;
}